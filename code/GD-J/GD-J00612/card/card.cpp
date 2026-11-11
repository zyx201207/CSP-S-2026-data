#include <iostream>
#include <unordered_set>

using namespace std;
typedef long long ll;

int n,m,a[500005],ans[500005];
unordered_set<int> s;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		s.clear();
		for(int j=i;j<=n;++j)
		{
			if(s.count(a[j])) s.erase(s.begin(),s.find(a[j]));
			else s.insert(a[j]);
		}
		for(int j=1;j<=m;++j) ans[j]+=s.count(j);
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' '; 
	return 0;
}

