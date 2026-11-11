#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n=0,m=0,maxn=-1;
    scanf("%d%d",&n,&m);
    long long a[n+2]={};
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    printf("%d",a[m]);
    return 0;
}
