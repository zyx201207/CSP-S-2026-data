#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000005
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3f
ll a[MAXN];
ll dis[MAXN];
bool is[MAXN];



int main()
{
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","w",stdin);
	int c,t;
	cin>>c>>t;
	while(t--) 
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<rand()%n;
	}
	
	return 0;
}
