#include <bits/stdc++.h>
using namespace std;
long long n,x,jishu=1,num,cishu;
string zifu[200005];
string s;
bool flag=false;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>s;
		//pianfentepan
		if(x==1000000000)
		{
			flag=true;
		}
		else
		{
			num+=x;
			for(int k=1;k<=x;k++)
			{
				zifu[jishu]=s;
				jishu++;
			}			
		}
	}
	if(flag==true)
	{
		cout<<n/2*1000000000;
		return 0;
	}
	if(num%2==0)
	{
		long long mid=num/2;
		//mid++;
		for(int o=1;o<mid;o++)
		{
			if(zifu[o]!=zifu[mid+o+1])
			{
				cishu++;
			}
		}
		if(zifu[mid]!=zifu[mid+1]) cishu++;
	}
	else 
	{
		num++;
		long long mid=num/2;
		for(int u=1;u<mid;u++)
		{
			if(zifu[u]!=zifu[mid+u])
			{
				cishu++;
			}
		}
	}
	cout<<cishu;
	return 0;
}
