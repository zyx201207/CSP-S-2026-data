#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,a[5000005];
long long cnt=0;
void solve(int i)
{
	int co=0;
	for(int no=i;no<n;no++)
	{
		if(a[no+2]-a[no]<=m && a[no+3]-a[no]>m) co++;
		else if(a[no+2]-a[no]>m && a[no+1]-a[no]<=m);
		else return;
		if(co==1 && no!=i) cnt++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			solve(i);
		}
		cout<<cnt<<endl;
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
 */
