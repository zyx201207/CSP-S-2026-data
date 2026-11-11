#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long s=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);

    for(int i=n;i>=n-m+2;i--){
        s=a[i]&a[i-1];
    }
    printf("%lld",s);




    return 0;
}
//1 3 7 15 31
