#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[300005];
bool flagSA=1;
long long hh[10005][5005],lst[5005],cnt[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++) if(a[i-1]>a[i]) flagSA=0;
	if(flagSA)
	{
		int js=0;
		for(int i=1;i<=n;i++)
		{
			js++;
			if(a[i]!=a[i+1])
				printf("%lld ",(js+1)/2+(i-js)*(js%2)),js=0;
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(cnt[a[i]])
		{
			for(int j=1;j<=m;j++)
				s[j]+=hh[a[i]][j];
		}
		else
		{
			for(int j=1;j<=m;j++)
				s[j]+=(hh[a[i]][j]=hh[a[i+1]][j]+(a[i]==j));
		}
		cnt[a[i]]++;
		lst[a[i]]=i;
	/*	printf("%lld:",a[i]);
		for(int j=1;j<=m;j++)
			printf("%lld ",hh[a[i]][j]);
		printf("\n");*/
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",s[i]);
	return 0;
}
