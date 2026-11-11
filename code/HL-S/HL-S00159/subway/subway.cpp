#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	 long long a,b,c,d,e;
	 long long m,sum = 0;
	 cin >> a >> b >> c >> d >> e;
	 long long w[m + 5],k[m * 500];
	 for (long long i = 1;i <= m;i++)
	 {
	 	cin >> w[i];
	 	sum += w[i];
	 }
	 cout << sum << endl;
	 sum = 0;
	 for (long long i = 1;i <= m;i ++)
	 {
	 	cin >> k[i];
	 	sum += k[i];
	  } 
	  cout << sum;
	return 0;
}
