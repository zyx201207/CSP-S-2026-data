#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1,j=1;i<=n;++i){
        while(a[i]*(i-j+1)-(s[i]-s[j-1])>m) j++;
        ans=max(ans,i-j+1);
    }
    printf("%d\n",ans);
	return 0;
} 
/*
回忆录？
我常常，追忆过去
算了
悠然心会，妙处难于君说
What do you want more than a happy ending?
The courage to move on.

以上材料引发了你怎么的联想和感悟？
请写一篇文章，字数不少于 800 字，体裁不限（cpp除外）
*/