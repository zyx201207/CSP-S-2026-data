#include<bits/stdc++.h>
using namespace std;
vector<vector<long long> > a(21,vector<long long>(21));

int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,h,o,p,x,y,z=0;
	cin >> c >>n>>m>>d>>q;
	for(long long i=1;i<1+n;i++)
	{
		cin >> h;
		for(long long j=1;j<=h;j++)
		{
			cin >> o >> p;
			a[i][o]=p;
		}
	} 
	cout << senld();
	return 0;
}
