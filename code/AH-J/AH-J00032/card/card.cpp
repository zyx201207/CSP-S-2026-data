#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[100005],b[100005],c[100005],x=1;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(1){
                for(int y=x;y>=1;--y){
                    if(a[j]==a[y]&&j!=y&&j<y){
                        for(int t=y;t<=j;t++){
                            a[t]=0;
                        }
                    }
                }
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
            b[i]=0;
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                b[i]+=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
