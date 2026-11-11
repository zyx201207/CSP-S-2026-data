#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],maxx,ans,s,ll,ss;
bool check(int x)
{
	int sum=0;
	for(int i=x-1;i>=1;i--)
		sum=sum+(a[x]-a[i]);
	return sum<=m;
}
priority_queue<int,vector<int>,greater<int> > q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	maxx=l;
	for(int i=1;i<=l;i++)
		q.push(a[i]),s+=(a[l]-a[i]);
	ll=a[l],ss=l;
	for(int i=l+1;i<=n;i++)
	{
		if(a[i]!=ll)s=s+ss*(a[i]-ll),ll=a[i];
		s+=(a[i]-ll),ss++;
		while(s>m)
			s-=(a[i]-q.top()),q.pop(),ss--;
		maxx=max(maxx,ss);
	}
	cout<<maxx;
	return 0;
}
