#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
long long int b, t;
int n, m;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i + 1] > a[i]){
			t = a[i + 1];
			a[i + 1] = a[i];
			t = a[i];
		}
	}
 	cout << a[m + 2];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
