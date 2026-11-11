#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>res,res1;int ans=0;
	for(int i=1;i<=n;i++)res.push_back(i);
	for(int i=30;i>=0;i--)
	{
		res1.clear();
		for(int j:res)if(a[j]&(1<<i))
			res1.push_back(j);
		if(res1.size()>=m)res=res1,ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}
