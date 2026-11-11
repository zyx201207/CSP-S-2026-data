#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;

int m,n,ans,a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int t=1000000;
	while(t--)
	{
		random_shuffle(a+1,a+min(n,32)+1);
		int k=a[1];
		for(int i=2;i<=m;++i)
		{
			k&=a[i];
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}

