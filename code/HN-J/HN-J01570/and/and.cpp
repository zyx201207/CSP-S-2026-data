#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+11;
ll n,m,a[N];
void solve()
{
	multiset<ll> st;
	vector<int> k;
	for(int i=1;i<=n;++i)st.insert(a[i]);
	int ans=0;
	for(int j=30;j>=0;--j)
	{
		int cnt=0;
		for(auto it:st)
		{
			cnt+=((it & (1<<j))!=0);
		}
		if(cnt>=m)
		{
			ans+=(1<<j);
//			cout<<j<<" "<<cnt<<'\n';
			for(auto it:st)
			{
				if(!(it & (1<<j)))
				{
					k.push_back(it);
				}
			}
			for(auto it:k)st.erase(st.find(it));
			k.clear();
		}
	}
	cout<<ans<<"\n";
}
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	solve();
	return 0;
}
/*
9:07 start

4 2
3 15 12 12


5 3
31 3 1 15 7

9:30 end
so easy!!!
*/
