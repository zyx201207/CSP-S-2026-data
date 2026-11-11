#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ls[500005],t[500005],ll;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        memset(ls,0,sizeof(ls));
        for(int j=i;j<=n;j++){
            ls[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            for(int l=i;l<=j;l++){
                if(ls[j]==ls[l]){
                    for(int k=l;k<j;k++)ls[k]=0;
                }
            }
        }
        for(int j=1;j<=n;j++){
            t[ls[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<' ';
    return 0;
}
