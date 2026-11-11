#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],b[300005],c[300005]={0},d[300005]={0},k=1;
void ans(int x,int y){
    if(a[x]==a[y]){
        for(int o=x;o<y;o++){
            b[o]=0;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int op=1;op<=m;op++){
        k=1;
        for(int i=op;i<=n;i++){
            b[i]=a[i];
            for(int j=op;j<i;j++){
                ans(j,i);
            }
        }
        for(int i=op;i<=m;i++){
            if(b[i]!=0 && b[i]!=c[k]){
                d[k]++;
            }
            k++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
