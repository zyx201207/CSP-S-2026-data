#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s[200005];string a;
	int max_1 = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=a.size();i++){
		s[i] = (int)a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(s[i] & s[j] > max_1)
			{
				max_1 = s[i] & s[j];
			}
		}
	}
	if(m == 1 || m == n || m == 2 || m <= n || m == n-1)
	{
		cout << pow(2,20);
	}
	else
	{
		cout << max_1;
	}
	return 0;
}

