#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],c[N],cnt;
char s[N],g[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int i=1;i<=n;i++)
	{
		if(g[cnt]==s[i]) c[cnt]+=a[i];
		else
		{
			c[++cnt]=a[i];
			g[cnt]=s[i];
		}
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j)
	{
		long long res=min(c[i],c[j]);
		if(g[i]!=g[j])ans+=res;
		c[i]-=res;
		c[j]-=res;
		if(c[i]==0)i++;
		if(c[j]==0)j--;
	}
	cout<<ans<<endl;
	return 0;
}