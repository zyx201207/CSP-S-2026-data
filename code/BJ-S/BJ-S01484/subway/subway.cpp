#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=500005;
const int Q=100005;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        bool f1=0,f2=0;
        int id1,id2;
        long long ans=0;
        if(n==2){
            for(int i=1;i<=k[1];i++){
                if(a[1][i]==x){
                    f1=1;
                    id1=i;
                }
                if(a[1][i]==y){
                    f2=1;
                    id2=i;
                }
            }
            if(f1==1&&f2==1){
                ans=w[a[1][id1]]+t[1][id1]+t[1][id2]+w[a[1][id2]];
            }else if(f1==0&&f2==0){
                for(int i=1;i<=k[2];i++){
                    if(a[2][i]==x)id1=i;
                    if(a[2][i]==y)id2=i;
                }
                ans=w[a[2][id1]]+t[2][id1]+t[2][id2]+w[a[2][id2]];
            }else if(f1==1&&f2==0){
                for(int i=1;i<=k[1];i++){
                    for(int j=1;j<=k[2];j++){
                        if(a[1][i]==a[2][j]){
                            ans+=t[1][i]+t[2][j];
                            break;
                        }
                        if(a[2][j]==y)id2=j;
                    }
                }
                ans+=w[a[1][id1]]+t[1][id1]+t[2][id2]+w[a[2][id2]];
            }else{
                for(int i=1;i<=k[1];i++){
                    for(int j=1;j<=k[2];j++){
                        if(a[1][i]==a[2][j]){
                            ans+=t[1][i]+t[2][j];
                            break;
                        }
                    }
                    if(a[1][i]==y)id1=i;
                }
                ans+=w[a[1][id1]]+t[1][id1]+t[2][id2]+w[a[2][id2]];
            }
            cout<<ans<<"\n";
            continue;
        }

    }
    return 0;
}
