#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100000],t[100000][10000][3];
long long sum=0,x=0,y=0,e=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>e;
        t[i][0][0]=e;
        for(long long j=1;j<=e;j++){
            cin>>t[i][j][1]>>t[i][j][2];
        }
    }

    for(long long i=1;i<=q;i++){
        cin>>x>>y;
        sum+=w[x]+w[y];
        for(long long j=1;j<=n;j++){
            int f=0,g=0,h=0;
            for(long long k=1;k<t[j][0][0];k++){
                if(t[j][k][1]==x) f=1,g=k;
                if(t[j][k][1]==y) f=1,h=k;
            }
            if(f==1){
                for(long long k=g;k<=h;k++){
                    sum+=t[j][k][2];
                }
            }
        }
        cout<<sum;
    }
}
