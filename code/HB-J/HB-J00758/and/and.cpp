#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000000],b[1000000],ans=0;
bool cmp(int x,int y){
    if(x>y)return 1;
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    printf("%lld",ans);
    return 0;
}
