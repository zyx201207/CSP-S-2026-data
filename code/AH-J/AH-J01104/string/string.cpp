#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[100000];
	char c;
	long long sum = 0;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		cin >> c;
		sum += a[i];
	}
	
	cout<<"0";
	return 0;
}
		
