#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a1,a2,b1,b2,sum[4];
	char c1,c2;
	for(int i=1;i<=4;i++) sum[i]=0;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	int x1=c1,x2=c2;
	if(a1==a2) sum[1]=1;
	else sum[1]=0;
	if(sum[1]==1 and b1==b2) sum[2]=1;
	else
	{
		cout<<sum[1]<<sum[2]<<sum[3]<<sum[4];
		return 0;
	}
	if(x1<=67 && x2<=67 || x1>67 && x2>67) sum[3]=1;
	else sum[3]=0;
	if(sum[3]==1)
	{
	if(x2==x1-1 || x2==x1+1) sum[4]=1;
	else sum[4]=0;
	}
	cout<<sum[1]<<sum[2]<<sum[3]<<sum[4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
