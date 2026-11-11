#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2 * 100010;

int a[N];
int ans,n,m;

void dfs(int x, int tmp, int f)
{	
	if(x == n + 1)
	{
		cout<<tmp<<endl;
		ans = max(ans,tmp);
		return;
	}

	dfs(x+1,tmp,f);
	if(f < m) dfs(x+1,tmp & a[x],f + 1);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	
	for(int i = 1;i<=n;i++) cin>>a[i];
	dfs(1,a[1],0);
	cout<<ans<<endl;
	
	return 0;
}
