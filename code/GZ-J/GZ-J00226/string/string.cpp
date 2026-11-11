//GZ-J00226 ·ëè÷ôË
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,summ=0;
vector<pair<ll,char>> a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    a.push_back({-1,'-1'});
    for(int i=1;i<=n;++i){
        a.push_back({0,'0'});
        cin>>a[i].first>>a[i].second;
    }
    ll l=1,r=n;
    while(l<=r){
        if(a[l].first<=0)l++;
        if(a[r].first<=0)r--;
        ll ps=min(a[l].first,a[r].first);
        if(a[l].second!=a[r].second){
            summ+=min(a[l].first,a[r].first);
            a[l].first-=ps;
            a[r].first-=ps;
        }else{
            a[l].first-=ps;
            a[r].first-=ps;
        }

    }
    cout<<summ<<endl;
	return 0;
}
