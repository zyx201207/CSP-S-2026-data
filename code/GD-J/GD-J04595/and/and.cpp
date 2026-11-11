#include<bits/stdc++.h>
using namespace std;
long long tsq;
int n,m,a[200001];
int cnt[200001];
int num[200001][31];
bool vis[200001];
long long anss;
long long summ[50];
int cntt;
int ans[50];
int sum[50];
bool mp(int x,int y)
{
	return x>y;
}
bool s(int x)
{
	for(int i=1;i<=cntt;i++) if(num[x][ans[i]]==0) return 0;
	return 1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,mp);
	summ[1]=1;
	for(int i=2;i<=31;i++) summ[i]=summ[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=0)
		{
			cnt[i]++;
			num[i][cnt[i]]=a[i]%2;
			a[i]/=2;
		}
	}
	while(1)
	{
		bool df=0;
		for(int j=31;j>=1;j--) sum[j]=0;
		for(int i=1;i<=n;i++) if(s(i)==1) {
			for(int j=cnt[i];j>=1;j--) if(vis[j]==0) sum[j]+=num[i][j];
		}
		for(int j=31;j>=1;j--) if(sum[j]>=m) {
			cntt++;
			ans[cntt]=j;
			vis[j]=1;
			anss=anss+summ[j];
			df=1;
			break;
		}
		if(df==0) break;
	}
	printf("%lld",anss);
	return 0;
}
//5 3
//31 3 1 15 7
