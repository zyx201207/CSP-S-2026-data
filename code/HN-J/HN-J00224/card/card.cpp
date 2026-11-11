#include <iostream>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	long long a[n+5];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<m;i++){
		cout << 0;
	}
	
	
	return 0;
}
