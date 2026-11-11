#include <bits/stdc++.h>
using namespace std;
int f[2005][2005];
int w[2005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c<7||c>11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(k==1) cin>>k;
            vector<int> xx;
            vector<int> yy;
            for(int i=0;i<k;i++){
                int x,y;
                cin>>x>>y;
                xx.push_back(x);
                yy.push_back(y);
            }
            for(int i=0;i<xx.size();i++){
                for(int j=0;j<xx.size();j++){
                    f[xx[i]][xx[j]]=yy[i]+yy[j];
                }
            }

        }
        for(int i=1;i<=m;i++){
            for(int k=1;k<=m;k++){
                for(int j=1;j<=m;j++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                    
                }
                // cout<<f[i][k]<<" ";
            }
            // cout<<endl;
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<w[l]+w[r]+f[l][r]<<endl;
        }
    }
    if(c>=7&&c<=11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(k==1) cin>>k;
            else{
                int a1,t1,a2,t2;
                cin>>a1>>t1>>a2>>t2;
                f[a1][a2]=f[a2][a1]=t1+t2;
            }
            f[i][i]=w[i]*2;
        }
        
        for(int i=1;i<=m;i++){
            for(int k=1;k<=m;k++){
                for(int j=1;j<=m;j++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                    
                }
                // cout<<f[i][k]<<" ";
            }
            // cout<<endl;
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<w[l]+w[r]+f[l][r]<<endl;
        }
    }
    return 0;
}