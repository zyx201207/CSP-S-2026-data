#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin >> n >> d;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin << a[i];
		cout << n*(n+1)/2 << endl;
	}
	
	return 0;
}
