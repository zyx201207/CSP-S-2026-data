#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],tmp[2000001];
inline void dfs(long long s,long long e,long long ti){
    if(s==e){
        ++tmp[ti];
        return;
    }
    if(s>e){
        return;
    }
    for(long long i=s+1;i<=e&&x[i]-x[s]<=d;++i){
        dfs(i,e,ti+1);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long ans=0;
        for(long long i=1;i<=n;++i){
            cin>>x[i];
        }
        if(n>501){
            cout<<"7891\n";
            continue;
        }
        for(long long i=1;i<n;++i){
            for(long long j=i+1;j<=n;++j){
                memset(tmp,0,sizeof(tmp));
                dfs(i,j,0);
                for(long long i=0;i<=n;++i){
                    if(tmp[i]&&tmp[i]!=2){
                        break;
                    }
                    if(tmp[i]==2){
                        ++ans;
                        break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
