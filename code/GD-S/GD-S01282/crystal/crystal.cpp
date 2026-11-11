#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10;
ll n,m,ans,cnt,a[N],diff,res;
priority_queue<ll,vector<ll>,greater<ll>> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=ans=1;
	q.push(a[1]);
	for(int i=2;i<=n;i++)
	{
//		cout<<a[i]<<' ';
		diff=a[i]-a[i-1];
		res=res+1ll*ans*diff;
		if(res>m)
		{
			while(1ll*ans*diff<a[i]-q.top()&&res>m)
			{
				q.pop();
				res-=a[i]-q.top();
				ans--;
			}
//			cout<<res<<endl;
		}
		q.push({a[i]});
		ans++;
		if(res<=m) cnt=max(cnt,ans);
	}
	cout<<cnt;
	return 0;
}

