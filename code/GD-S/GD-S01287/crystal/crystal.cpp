#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
long long a[maxn],s[maxn];
bool check(int l,int r)
{
	if((s[r]-s[l-1])+m>=1ll*(r-l+1)*a[r])return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int maxx=1;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int j=1;
	for(int i=2;i<=n;i++)
	{
		while(!check(j,i))j++;
		maxx=max(maxx,i-j+1);
	}
	cout<<maxx;
	return 0;
 } 
