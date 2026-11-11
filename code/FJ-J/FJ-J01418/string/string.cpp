#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	string s;
}a[200005];
string fz(string n)
{
	string res;
	for(int i=n.size();i>0;i--)
	{
		res=n[i];
	}
	return res;
	
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int m;
    cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].s;
	}  
	if(m==1)
    {
    	cout<<0;
    	return 0;
	}
	string num;
	for(int i=1;i<=m;i++)
	{
		if(m==2&&a[1].s!=a[2].s)
		{
			cout<<min(a[1].x,a[2].x);
			return 0;
		}
		if(m==2&&a[1].s==a[2].s)
		{
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i].x;j++)
		{
			num+=a[i].s;
		}
	}
	if(num==fz(num))
	{
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<num.size();i++)
	{
		if(num[0]!=num[num.size()-i])
		{
			num[num.size()-i]=num[0];
			cnt++;
		
		}
		if(fz(num)==num)
		{
			break;
		}
		
	}
	cout<<cnt-1;
	return 0;
}
