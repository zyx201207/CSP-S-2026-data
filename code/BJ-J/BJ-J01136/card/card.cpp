#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100,M=1e5+100;
int n,m,a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int x=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])x=0;
    }
    if(x==0){
        for(int i=1;i<=n;i++){
            int f[5005]={0},len=0;
            for(int j=i;j<=n;j++){
                if(len==0){
                    f[++len]=a[j];
                }else{
                    bool flag=1;
                    for(int k=len;k>=1;k--){
                        if(f[k]==a[j]){
                            for(int jjj=k+1;jjj<=len;jjj++)f[jjj]=0;
                            len=k;
                            f[len]=a[j];
                            flag=0;
                            break;
                        }
                    }
                    if(flag)f[++len]=a[j];
                }
            }
            for(int j=1;j<=len;j++){
                ans[f[j]]++;
                //if(f[j]==1)cout<<i<<" ";
            }
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    }else{
        for(int i=1;i<=n;i++){
            ans[a[i]]++;
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    }
    return 0;
}
