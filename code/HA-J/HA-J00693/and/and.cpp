#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

const int MAXN=400005;

int n,m;
int a[MAXN];
bool b[MAXN];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for (int i=1;i<=n;i++) b[i]=1;
	
	int ans=0;
	for (int t=30;t>=0;t--)
	{
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (!b[i]) continue;
			if ((a[i]>>t)&1) cnt++;
		}
		if (cnt<m) continue;
		for (int i=1;i<=n;i++)
		{
			if (!b[i]) continue;
			if (!((a[i]>>t)&1)) b[i]=0;
		}
		ans|=(1<<t);
	}
	printf("%d",ans);
	
	return 0;
}
