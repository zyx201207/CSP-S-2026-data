#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans;
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		q.push(a); 
	}
	for(long long i=1;i<=m;i++)
	{
		long long x;
		x=q.top();
		q.pop();
		q.push(x+1);
	}
	long long x=q.top();
	for(long long i=1;i<=n;i++)
	{
		if(q.top()==x)
		{
			ans++;
			x=q.top();
			q.pop();
		}
		else
		{
			break;
		}
	}
	printf("%lld",ans);

	return 0;
}

