
#include<bits/stdc++.h>
//Oct31==Dec25?
using namespace std;
int main(){
    freopen("migrate.in","w",stdin);
    freopen("migrate.out","r",stdout);
    long long c,n,m,d,q,w[1005],k[500][555],r,x,t[1003],ans;
    cin>>c>>n>>m>>d>>q;

        for(int i=0;i<m;i++){
            cin>>w[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    cin>>k[i][j];
            }
            cin>>t[i];
        }
         for(int i=0;i<1;i++){
                cin>>r>>x;
         }
       ans=w[r]+t[r][r]+t[r][x]+t[x][x]+t[x]+w[x];
        cout<<ans;
return 0;
}

