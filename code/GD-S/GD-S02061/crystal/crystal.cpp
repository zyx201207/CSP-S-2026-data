#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
ll n,m,a[N],ans,sum;
deque<ll>q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum=ans=a[1];
	q.push_back(a[1]);
	for(int i=2;i<=n;i++)
	{
		while((!q.empty())&&(a[i]*q.size()-sum>m)) sum-=q.front(),q.pop_front();
		q.push_back(a[i]);
		sum+=a[i];
		ans=max(ans,(ll)q.size());
	}
	cout<<ans;
	return 0;
}
