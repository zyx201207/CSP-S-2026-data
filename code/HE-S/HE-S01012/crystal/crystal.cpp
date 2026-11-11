#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
const int N=5e5+5;
int n;intt m;
intt a[N],s[N];
intt sum(int l,int r){return s[r]-s[l-1];}
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n),scanf("%lld",&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&a[j]*(j-i+1)-sum(i,j)<=m) j++;
		j--;ans=std::max(ans,j-i+1);
	}
	printf("%d",ans);
	return 0;
}
