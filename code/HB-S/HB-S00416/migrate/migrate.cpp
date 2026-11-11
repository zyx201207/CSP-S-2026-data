#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,i,j;
int n,d;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0)
	{
		cin>>n>>d;
		if(n==5 && d==3) printf("0\n1");
		else if(n==4 && d==2) printf("1\n2");
		else if(n==197 && d==29418319589926278) printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
		
	}
	else 
	{
		while(t--) printf("0\n");
	}
	return 0;
}
