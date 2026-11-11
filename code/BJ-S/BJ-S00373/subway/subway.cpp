#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int v[1005],t[1005];
int k[1005];
int w[1005];
int len=0;
int a[1005][1005];
long long ans=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>v[j]>>t[j];
            a[i][j]=t[j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    flag=true;
                }
                if(flag)ans+=a[i][j];
                if(a[i][j]==y)break;
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
