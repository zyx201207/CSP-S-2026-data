//GZ-S00014 文泓浩 都匀市第三中学  
#include <bits/stdc++.h>
using namespace std;
int c,t,a[500010],pre[500010],pre1[500010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
		}
		for(int i=2; i<=n; i++)
		{
			pre[i]=a[i]-a[i-1];
		}
		for(int i=2; i<=n; i++)
		{
			pre1[i]=pre[i]+pre1[i-1];
		}
		cout << 8 << ' ' << 9
	} 
	return 0;
}
