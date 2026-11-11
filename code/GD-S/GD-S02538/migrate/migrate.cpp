#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
map<long long,bool> mp;
vector<long long> a;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t)
	{
		mp.clear();
		a.clear();
		--t;
		int n;
		long long d;
		cin>>n>>d;
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			a.push_back(x);
			mp[x]=true;
		}
		sort(a.begin(),a.end());
		long long ans=0;
		for(int i=0;i<n;++i)
		{
			long long x1=a[i]+d;
			if(mp[x1]&&mp[x1-1]&&mp[x1-1+d])
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
