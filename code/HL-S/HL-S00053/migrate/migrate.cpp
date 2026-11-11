#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define int long long
using namespace std;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	int c,T;
	cin >> c >> T;
	while (T--){
		cout << rand() % 50 << endl;
	}
}
