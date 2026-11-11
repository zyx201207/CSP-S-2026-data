#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>> q;
int n;
long long m,ans[1000005],fans[1000005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(ans,0,sizeof(ans));
	memset(fans,0,sizeof(fans));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long a;cin>>a;
		q.push(a);
	}
	for(int i=m;i>0;i--)
	{
		long long a=q.top();
		a++;
		q.pop();
		q.push(a);
	}
	long long maxn1=0,maxn2=0;
	while(!q.empty())
	{
		if(q.top()<0)
		{
			long long b=q.top();
			b*=-1;
			fans[b]++;
			maxn2=max(maxn2,b);
		}
		else 
		{
			long long a=q.top();
			maxn1=max(maxn1,a);
			ans[a]++;
		}
		q.pop();
	}
	sort(ans,ans+maxn1,cmp);
	sort(fans,fans+maxn2,cmp);
	cout<<max(ans[0],fans[1]);
	return 0;
}
