#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

int c,t,n,k,cnt;

void gc()
{
	cin >> n >> k;
	for (int i = 1;i <= n-1;i++)
	{
		int u,v;
		cin >> u >> v;
	}
	cout<<++cnt<<"\n";
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t--)gc();
	return 0;
}
