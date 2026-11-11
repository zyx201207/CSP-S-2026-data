#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int a[N],nu[N+1];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<i;j++){
            if(a[j]==a[i])
                for(int k=j+1;k<=i;k++) a[k]=0;
        }
        for(int j=0;j<=i;j++) nu[a[j]]++;
    }
    for(int i=1;i<=m;i++) printf("%d",nu[i]);
    return 0;
}
