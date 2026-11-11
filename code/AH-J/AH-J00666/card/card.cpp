#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N],t[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>2000&&n<=3e4){
        for(int i=1;i<=n;i++){
            memset(c,0,sizeof(c));
            int cnt=0;
            for(int j=i;j<=n;j++){
                bool f=1;
                for(int k=cnt;k>=1;k--){
                    if(c[k]==a[j]){
                        f=0,cnt=k-1;
                        break;
                    }
                    if(c[k]!=a[j]) break;
                }
                c[++cnt]=a[j];
            }
            for(int j=1;j<=cnt;j++) t[c[j]]++;
        }
        for(int i=1;i<=m;i++) cout<<t[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof(c));
        int cnt=0;
        for(int j=i;j<=n;j++){
            bool f=1;
            for(int k=cnt;k>=1;k--){
                if(c[k]==a[j]){
                    f=0,cnt=k-1;
                    break;
                }
            }
            c[++cnt]=a[j];
        }
        for(int j=1;j<=cnt;j++) t[c[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
