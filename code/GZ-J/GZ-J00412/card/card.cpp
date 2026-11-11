//GZ-J00412 贵阳市观山湖区普瑞学校 袁雅琪
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long b,c=1,d,n,m,i,j,h=0;

	cin>>n>>m;
	int a[n]={};
	for(i=0;i<n;i++)
	{
		cin>>a[i];

	}
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			c=c*i;
		}
		cout<<c;
	}
	else
	for(i=0;i<m;i++)
    {

        cout<<i+1<<"";
    }
	return 0;
}
