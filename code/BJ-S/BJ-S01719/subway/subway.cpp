#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int w[N];
int k1,k2,k3;
int p1[N],p2[N],p3[N];
int r1[N],r2[N],r3[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cin>>k1;
    for(int i=1;i<=k1;i++){
        cin>>p1[i]>>r1[i];
    }
    cin>>k2;
    for(int i=1;i<=k2;i++){
        cin>>p2[i]>>r2[i];
    }
    cin>>k3;
    for(int i=1;i<=k3;i++){
        cin>>p3[i]>>r3[i];
    }
    for(int i=1;i<=q;i++){
        long long ans=0;
        int x,y;
        cin>>x>>y;
        ans+=w[x]+w[y];
        //cout<<w[x]<<" "<<w[y]<<endl;
        ans+=r1[x]+r3[y];
        //cout<<r1[x]<<" "<<r3[y]<<endl;
        if(n==3){
            for(int j=1;j<=k1;j++){
                for(int l=1;l<=k2;l++){
                    if(p1[j]==p2[l]){
                        ans+=r1[j]+r2[l];
                        //cout<<r1[j]<<" "<<r2[l]<<endl;
                        break;
                    }
                }
            }
            for(int j=1;j<=k2;j++){
                for(int l=1;l<=k3;l++){
                    if(p2[j]==p3[l]){
                        ans+=r2[j]+r3[l];
                        //cout<<r2[j]<<" "<<r3[l]<<endl;
                        break;
                    }
                }
            }
        }cout<<ans;
    }
    return 0;
}
