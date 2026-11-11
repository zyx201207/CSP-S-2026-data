#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b)
{
	return a>b;
}
int ans=0;
int main() 
{
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int cnt=1;
	for(int j=1;j<=m;j++)
	{
		ans=a[j];
		for(int i=1;cnt<m&&i<=n;i++)
		{
			if(i==j) continue;
			int tmp=a[i]&ans;
			if(tmp==0) continue;
			else ans=ans&a[i],cnt++;
		}
	}
	printf("%d",ans);
	return 0;
}
