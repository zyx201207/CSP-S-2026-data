#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1002;
int c,n,m,d,qe,a[N],l,l2=0,t1,t2,pr=0,f[N][N];
struct node{
    int v,w;
};
//vector<node> g[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qe;l2=m+1;
    for(int i=1;i<=m;i++){
        cin>>a[i];//cout<<a[i]<<" ";
    }
    //cout<<"\n\n";
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            f[i][j]=1e18;
        }
        f[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>l;
        for(int j=1;j<=l;j++){
            cin>>t1>>t2;
            //g[t1].push_back({l2,t2});
            f[t1][l2]=t2;
            //g[l2].push_back({t1,t2});
            f[l2][t1]=t2;
            if(j>1){
                //g[l2].push_back({pr,0});
                f[l2][pr]=0;
                //g[pr].push_back({l2,0});
                f[pr][l2]=0;
            }
            pr=l2;l2++;
        }
    }
    //int u,v,w;
    //queue<int> q;
    for(int k=1;k<l2;k++){
        for(int i=1;i<l2;i++){
            for(int j=1;j<l2;j++){
                if(f[i][k]+f[k][j]<f[i][j]){
                    f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
    }
    while(qe--){
        cin>>t1>>t2;
        cout<<f[t1][t2]+a[t1]+a[t2]<<"\n";
    }
    return 0;
}
