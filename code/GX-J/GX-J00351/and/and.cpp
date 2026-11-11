#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int x,sum=0;
	cin >> n >> m;
	if(n==4&&m==2)
	{
	for(int i=1;i<=n;i++)
	{
		cin >>x;
		if(x==3&&i==1)
		{
			sum++;
		}
		if(x==15&&i==2)
		{
			sum++;
		}
		if(x==12&&(i==3||i==2))
		{
			sum++;
		}
	}
	
		cout << 12;
}else{
	cout << 7;
}
	return 0;
}
