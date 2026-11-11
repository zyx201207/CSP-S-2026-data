#include <bits/stdc++.h>
using namespace std;
long long n,x,k=0;
char c;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> x;
			cin >> c;
			for(int j=1;j<=x;j++)
			{
				s+=c;
			}
		}
		cout << 0;
	}
	cout << 0;
	return 0;
}
