#include <bits/stdc++.h>;
using namespace std;
int c,n,m,d,q;
int w[500005];
struct str{
	int s;
	int t;
}a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int j=1;j<=n;j++){
	
		int x;
		cin>>x;
 		for(int i=1;i<=x;i++)
		{
			cin>>a[i].s>>a[i].t;
		}
		
	}
	
	
	return 0;
}
