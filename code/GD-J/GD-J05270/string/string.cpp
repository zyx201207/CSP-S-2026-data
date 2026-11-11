#include <iostream>
#include <string>
using namespace std;

int sum = 0, l = 0, r = 0, k[200005],sumk[200005],n,ans =0;
string c[200005];
int main()
{
	cin >> n;
	sumk[0] = 0;
	for(int i = 1; i<= n; i++)
	{
		cin >> k[i] >> c[i];
		sumk[i] = sumk[i-1] + k[i];
	}
	while(sumk[l] <= sumk[n] / 2 + sumk[n] % 2)
	{
		l++;
	}
	r = l;
	if(sumk[sum] == sumk[n] / 2 + sumk[n] % 2) r++;
	
	for(int i = sumk[n] / 2 + sumk[n] % 2; i >= 1; i++)
	{
		if(c[l] != c[r])
		ans++;
		if(sumk[l-1] >= i)	l--;
		if(sumk[r] < sumk[n] -i)	r++;
	}
	cout << ans;
	return 0;
}
