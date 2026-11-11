#include<bits/stdc++.h>
using namespace std;
long long tsq;
int n,m,a[500001];
int last[500001];
int cnt;
int ans[500001];
int vis[500001];
int sum[500001];
bool s()
{
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) return 0;
	return 1;
}
int ss(int x)
{
	for(int i=1;i<=cnt;i++) if(ans[i]==x) return i;
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(s()==1) {
		for(int i=1;i<=n;i++) last[a[i]]=i;
		for(int i=1;i<=m;i++) printf("%d ",last[i]);
	}
	else {
		for(int i=1;i<=n;i++) {
			cnt=0;
			for(int j=i;j<=n;j++) {
				int df=ss(a[j]);
				if(df==-1) {
					cnt++;
					ans[cnt]=a[j];
				}
				else cnt=df;
			}
			for(int j=1;j<=cnt;j++) vis[ans[j]]=1;
			for(int j=1;j<=m;j++) {
				sum[j]+=vis[j];
				vis[j]=0;
			}
		}
		for(int j=1;j<=m;j++) printf("%d ",sum[j]);
	}
	return 0;
}

