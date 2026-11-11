#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],b[500002],c[300002];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int p=i;p<=j;p++){
                if(b[p]==a[j]){
                    for(int q=p;q<j;q++)b[q]=-1;
                    break;
                }
            }
            b[j]=a[j];
        }
        for(int j=i;j<=n;j++) c[b[j]]++;
    }
    for(int i=1;i<=m;i++) printf("%d ",c[i]);
    return 0;
}
