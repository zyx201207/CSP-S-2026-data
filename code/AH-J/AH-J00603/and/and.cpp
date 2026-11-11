#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[200005];
int com(int aaa,int bbb){
    return aaa&bbb;
}
void dfs(int num,int w,int why){
    if(num==m){if(why>ans)ans=why;return;}
    for(int i=w+1;i<=n-m+num+1;i++)
        dfs(num+1,i,com(why,a[i]));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n-m+1;i++)dfs(1,i,a[i]);
    printf("%lld",ans);
    return 0;
}
