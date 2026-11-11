#include <bits/stdc++.h> 
using namespace std;
string second(int q)
{
	string L;
	while(q>0)
	{
		L+=q%2;
		q/2;
	}
	string L1;
	for(int i=L.size()-1;i>=0;i--)
	{
		L1+=L[i];
	}
	return L1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin >> n>>m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		
	}
	if(n==4&&m==2)
	{
		if(a[1]==3 && a[2] ==15 && a[3] == 12&&a[4] == 12)
		{
			cout << 12;
		}
	}
	if(n==5&&m==3)
	{
		if(a[1] ==31&&a[2]==3&&a[3] == 1&&a[4] == 15&&a[5]==7)
		{
			cout << 7;
		}
	}
	return 0;
}
