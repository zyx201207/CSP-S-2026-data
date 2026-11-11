#include<bits/stdc++.h>
using namespace std;
priority_queue<long long int>q;
int n,r=1,l=1;
long long int a[510000],m,ans=1,hao=0,e;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&e);
		q.push(e);
	}
	for(int i=1;i<=n;i++)
	{
		a[n-i+1]=q.top();
		q.pop();
	}
	for(int i=2;i<=n;i++)
	{
		if(hao+(i-1)*(a[i]-a[i-1])<=m)hao=hao+(i-1)*(a[i]-a[i-1]);
		else {
		r=i-1;
		break;
		}
	}
	ans=r;
	while(l<=r&&r<=n)
	{
		while(hao<=m&&r<n){
			r++;
			hao=hao+(r-l)*(a[r]-a[r-1]);
		}
		while(hao>m){
			hao=hao-(a[r]-a[l]);
			l++;
		}
		if(r-l+1>ans)ans=r-l+1;
		if(r==n)break;
	}
	printf("%lld",ans);
	return 0;
 } 
