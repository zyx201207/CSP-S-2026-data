#include <iostream>
#include <algorithm>
using namespace std;
int c,t,n,d,a[2000005];
void solve1()
{
	cin >> n >> d;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << max(0,(n-(d/(a[2]-a[1])*2)+1)) << "\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12)
	{
		while(t--)solve1();
	}
	return 0;
}
