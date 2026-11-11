#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[1000000],min = 1000000,id2,b,num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	while (m > 0){
		min = 1000000;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (i == j)
				{
					continue; 
				}
				if (a[i] > a[j]){
					b = a[i] - a[j];
				}
				else{
					b = a[j] - a[i];
				}
				if (b < min)
				{
					min = b;
					if (a[i] > a[j]){
						id2 = j;
					}
					else{
						id2 = i;
					}
				}
			}
		}
		if (min > m)
		{
			break;
		}
		a[id2] += min;
		num++;
		m -= min;
	}
	cout << num;
	return 0;
} 
