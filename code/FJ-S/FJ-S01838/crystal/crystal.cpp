#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;//水晶 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;//n为水晶数，m为可操作次数 
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end());
	int j=n-1;//前指针
	int delta=0;//差值
	int x=0;//步长 
	int ans=0;
	for(int i=n-1;i>0;i--)//后指针 
	{//此时i是后面那个
		while(j>0)//找后指针 
	{
		if(delta+a[i]-a[j-1]<=m)
		{
			delta+=a[i]-a[j-1];
			x++;
			j--; 
		}
		else
		break;
	}
	    if(ans<x+1)ans=x+1;
		delta-=x*(a[i]-a[i-1]);
		x--;
	}
	cout<<ans;
	return 0; 
 } 
