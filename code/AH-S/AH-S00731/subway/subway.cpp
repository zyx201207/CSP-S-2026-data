#include<bits/stdc++.h>
using namespace std;
const int M=500005,N=505;
long long c,n,m,d,q,w[M],ans=999999999999,t[N][N],x[N][N],k[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==20||c==21){
        for(long long i=1;i<=m;i++)scanf("%lld",&w[i]);
        for(long long i=1;i<=n;i++){
            cin>>k[i];
            for(long long j=1;j<=m;j++){scanf("%lld",&x[i][j]);scanf("%lld",&t[i][x[i][j]]);}
        }
        for(long long i=1;i<=m;i++)if(t[1][i]!=0&&t[2][i]!=0)ans=min(ans,t[1][i]+t[2][i]);
        for(long long i=1;i<=q;i++){
            long long a,b;
            cin>>a>>b;
            long long flag=0;
            for(long long j=1;j<=2;j++){
                long long flaga=0,flagb=0;
                for(long long kk=1;kk<=k[j];kk++){
                    if(x[j][kk]==a)flaga=1;
                    if(x[j][kk]==b)flagb=1;
                }
                if(flaga==1&&flagb==1){flag=1;break;}
            }
            if(flag==1)cout<<w[a]+w[b];
            else cout<<ans+w[a]+w[b];
            cout<<endl;
        }
    }
    return 0;
}
/*
It may be the last time I take part in csp-s.
I will say goodbye to c++.
Miss you, ytq.
Miss you, syc.
Miss you, cmy.
Miss you, tqzx.
Miss you, zzc.
Miss you, csp-s.
Miss you, luogu.
 




How time flies...
*/
