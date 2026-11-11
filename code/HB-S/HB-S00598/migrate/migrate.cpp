#include<bits/stdc++.h>
//8
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=2e6+10;
ll x[N];
ll del[N];
int n;
ll d;
int dp[20][20];
int dis[20][20];

inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        del[i]=x[i]-x[i-1];
    }//l~r
    memset(dis,0x3f,sizeof(dis));
    memset(dp,0,sizeof(dp));
    vector<int>a;
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        a.clear();
        if(__builtin_popcount(i)<=2)continue;
        for(int j=1;j<=n;j++){
            if((i>>(j-1))&1){
                a.push_back(j);
            }
        }
        bool f=0;
        if(__builtin_popcount(i)<=dis[a[0]][a[a.size()-1]]){
            if(__builtin_popcount(i)<dis[a[0]][a[a.size()-1]]){
                dis[a[0]][a[a.size()-1]]=__builtin_popcount(i);
                dp[a[0]][a[a.size()-1]]=0;
            }
            for(int i=1;i<a.size();i++){
                if(x[a[i]]-x[a[i-1]]>d){
                    f=1;
                    break;
                }
            }
            if(f)continue;
            dp[a[0]][a[a.size()-1]]++;
            // cout<<"  ::"<<i<<endl;
        }
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // cout<<i<<" "<<j<<endl;
            // cout<<dp[i][j]<<endl;
            if(dp[i][j]==2)ans++;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,_;
    cin>>c>>_;
    while(_--){
        solve();
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/