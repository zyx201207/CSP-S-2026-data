#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 2e5 + 5;
lnt a[N];
lnt n,m,ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin>>a[i];
	for(int i = 30; i>= 0; i--)
	{
		lnt mask = ans|(1<<i);
		int tot=0;
		for(int j = 1; j <=n;j++)
		if((a[j]&mask)==mask)tot++;
		if(tot>=m)ans=mask;
	}
	cout << ans << "\n";
	return 0;
} 	
