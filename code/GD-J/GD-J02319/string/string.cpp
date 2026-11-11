#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int u;
	long long midn = 0;
	string kk=0;
	cin >> n;
	char hj;
	for(int i = 1;i <= n;i++)
	{
		
		cin >> u >> hj;
		midn+=u;
		for(int j = 1;j <= u;j++)
		{
			kk+=hj;
		}
	} 
	long long ys = midn;
	midn/=2;
	long long pp = 0;
	int j = ys;
	for(int i= 1;i <= midn;i++)
	{ 
		if(kk[i] != kk[j]) pp++; 
		cout << kk[i] << " " << kk[j] << " ";
		j++;
	}
	cout << pp;

	return 0;
}
