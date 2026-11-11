#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,m,a[maxn];
vector<int>G[35],tmp;
void init(int id){
    tmp.clear();
    tmp=G[id];
    for(int i=0;i<=34;i++)G[i].clear();
    for(int a:tmp){
        int cnt=0,t=a;
        while(t){
            cnt++;
            if(t&1)G[cnt].push_back(a);
            t>>=1;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1,t,a;i<=n;i++){
        cin>>a;
        t=a;
        int cnt=0;
        while(t){
            cnt++;
            if(t&1)G[cnt].push_back(a);
            t>>=1;
        }
    }
    int ans=0;
    for(int i=32;i>=1;i--){
        if((int)G[i].size()>=m){
            ans+=pow(2,i-1);
            init(i);
        }
    }
    cout<<ans;
    return 0;
}

