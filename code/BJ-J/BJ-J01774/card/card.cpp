#include<bits/stdc++.h>
using namespace std;
int n,m,jushu,sise,op,flag;
int a[500005],b[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            flag=0;
            for(int j=1;j<=sise;j++){
                if(b[j]==a[i]){
                    op=j;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                b[sise+1]=a[i];
                sise++;
            }else{
                for(int j=n;j>=op;i--){
                    b[j]=-1;
                }
                //sise-=n-op+1;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=sise;j++){
                if(b[j]==i){
                    t[i]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
