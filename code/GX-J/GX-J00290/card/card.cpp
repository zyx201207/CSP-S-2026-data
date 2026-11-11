#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,x=0;
    cin>>n;
    int a[1005],y[1005];
    for(int i=0;i<n;i++){
        cin>>a[i];
        y[i]=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=x;j<=m;j++){
            int t=0;
            for(int u=0;u<n;u++){
                if(a[j]==y[u]){
                    t=1;
                    continue;
                }
                if(t){
                    y[u]=-1;
                }
            }
            if(t==0){
                    int c=0;
                for(int v=0;v<1005;v++){
                    if()
                }
            }
        }
    }
    return 0;
}
