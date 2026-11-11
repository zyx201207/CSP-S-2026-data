#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int,char>> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].first;
    } 
    int l=1,r=n;
    ll ans=0;
    while(l<r){
        if(a[l].first>a[r].first){
            if(a[l].second!=a[r].second) ans+=a[r].first;
            a[l].first-=a[r].first;
            a[r].first=0;
            r--;
        }
        else if(a[l].first<a[r].first){
            if(a[l].second!=a[r].second) ans+=a[l].first;
            a[r].first-=a[l].first;
            a[l].first=0;
            l++;
        }
        else{
            if(a[l].second!=a[r].second) ans+=a[l].first;
            a[l].first=a[r].first=0;
            l++;
            r--;
        }
    }
    cout<<ans<<'\n';
    return 0;
}