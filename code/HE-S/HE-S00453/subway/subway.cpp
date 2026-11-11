#include<bits/stdc++.h>
using namespace std;
const long long MAXN=10010;
 int c,n,m,d,q,w[MAXN],a[MAXN][MAXN],k[MAXN],t[MAXN][MAXN],x[MAXN],y[MAXN],z[MAXN];
 int r=0,r1;
int main(){
    freopen("subway.in","r",stdin);
     freopen("subway.out","w",stdout);
     long v[10010],v1[10010];
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
     for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];v[i]=0;
     }
     int s=0,s1=0,tm=1;
     for(int i=1;i<=q;i++){
         for(int j=1;j<=n;j++){
               for(int g=1;g<=k[j];g++){
                   if(a[j][g]==x[i]){
                        s=j;
						s1=g;
                        }
                        }
                        }

                        for(int j=1;j<=n;j++){
                            for(int g=1;g<=k[j];g++){
                                if(a[j][g]==y[i]){
                                    r=j;r1=g;
                                }
                            }
                        }
                        if(s==r){
                            v[i]=w[x[i]]+t[x[i]][x[i]]+t[x[i]][x[i]]+w[y[i]];

                        }
                        else{
                            for(int j=1;j<=k[s];j++){
                            for(int g=1;g<=k[r];g++){
                                if(a[s][j]==a[r][j]){
                               v[tm]=w[x[i]]+t[x[i]][x[i]]+t[x[i]][a[s][j]]+t[a[s][j]][a[s][j]]+t[a[s][j]][a[s][j]]+y[i]+w[y[i]];

                                tm++;
                                }
                            }
                            }
                        }
                   }
                   if(s!=r){
                    int mx=0;
                    for(int j=1;j<=tm;j++){
                        if(v[j]>mx)
                            mx=v[j];
                    }
                   }
         for(int i=1;i<=q;i++){
            if(i!=q){
                cout<<v[i]<<endl;
            }
            else cout<<v[i];
         }
    return 0;
}

