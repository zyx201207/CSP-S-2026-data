//GZ-J00412 贵阳市观山湖区普瑞学校 袁雅琪
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,i,j,k=0,h=0;
	char c;
	string d;
	cin>>a;
	long long b[a]={};
	for(i=0;i<a;i++)
	{
		cin>>b[i]>>c;

		for(j=0;j<b[i];j++)
		{
			d=d+c;
		}
		k=k+b[i];
	}
	for(i=0;i<k/2;i++)
	{
		if(d[i]!=d[k-1-i])
		{
			h++;

		}
	}
	cout<<h;
	return 0;
}
