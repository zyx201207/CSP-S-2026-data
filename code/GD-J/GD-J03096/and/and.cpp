#include<bits/stdc++.h>
using namespace std;
int n ,m ,a[200010] ,ma ,sum;
int main() {
	freopen ("and.in" ,"r" ,stdin);
	freopen ("and.out" ,"w" ,stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int l = i + 1; l <= n; l++)
		{
			int j = l + 1;
			sum = a[i] & a[j] & a[l];
			ma = max(sum ,ma);
		}
	}
	cout << ma;
}
