#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    printf("%d",a[m]);
    return 0;
}
