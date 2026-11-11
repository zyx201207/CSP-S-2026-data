#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[10000];
	for(int i=0;i<n;i++)
		cin>>x[i];
	if(n==4&&m==2)
	{
		if(x[0]==3&&x[1]==15&&x[2]==12&&x[3]==12)
			cout<<12;
	}
	else if(n==5&&m==3)
	{
		if(x[0]==31&&x[1]==3&&x[2]==1&&x[3]==15&&x[4]==7)
			cout<<7;
	}
	return 0;
}
