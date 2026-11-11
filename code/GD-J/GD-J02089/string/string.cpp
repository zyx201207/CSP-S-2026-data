#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
char b[N];
long long n , cnt;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i];
	long long i = 1;
	while (i < n)
	{
		if (b[i] != b[n])
		{
			if (a[i] > a[n])
			{
				cnt += a[n];
				a[i] -= a[n];
				n--;
			}
			else if (a[n] > a[i])
			{
				cnt += a[i]; 
				a[n] -= a[i];
				i++;
			}
			else
			{
				cnt += a[i];
				i++;
				n--;
			}	
		}
		else 
		{
			if (a[i] > a[n])
			{
				a[i] -= a[n];
				n--;
			}
			else if (a[n] > a[i])
			{
				a[n] -= a[i];
				i++;
			}
			else
			{
				i++;
				n--;
			}
		}
	}
	cout << cnt; 
	fclose(stdin);
	fclose(stdout);
}
