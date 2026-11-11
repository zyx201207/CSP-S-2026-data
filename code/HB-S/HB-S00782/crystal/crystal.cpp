#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        printf("%lld ",a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}