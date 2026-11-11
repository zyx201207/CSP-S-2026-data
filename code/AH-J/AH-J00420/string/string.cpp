#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,cnt;
vector<pair<int,char>> v(N);
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int i=1,j=n;
    while(i!=j){
        if(v[i].second!=v[j].second){
            cnt+=min(v[i].first,v[j].first);
        }
        v[i].first-=min(v[i].first,v[j].first);
        v[j].first-=min(v[i].first,v[j].first);
        if(v[i].first==0){i++;}
        if(v[j].first==0){j--;}

    }
    cout<<cnt;
    return 0;
}
