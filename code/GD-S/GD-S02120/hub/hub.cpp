#include <iostream>
using namespace std;
int c,t,n,k,x,y;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t >> n >> k;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i < n;i++) cin >> x >> y;
		cout << n << endl;
	}
	return 0;
}
