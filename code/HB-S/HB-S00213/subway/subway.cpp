#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005];
int k;
int a[1005][1005],t[1005][1005];
int k[1005];
struct node{
    int x,y;
}ak[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k*2;j++){
            if(j%2==1){
                cin>>a[i][j];
            }
            else{
                cin>>t[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>ak[i].x>>ak[i].y;
        cout<<w[ak[i].x]+t[ak[i].x]+w[ak[i].y]+t[ak[i].y]<<endl;
    }
    return 0;
}
