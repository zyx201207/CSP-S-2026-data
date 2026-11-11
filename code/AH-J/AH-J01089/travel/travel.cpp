#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string x,y;
	int ans=0;
	cin>>a>>b>>x>>y;
	int l,r;
	if(a==x)
	{
		ans++;
	}
	if(b[0]==y[0]&&b[1]==y[1]&&ans==1)
	{
		ans++;
	}
	l=b[2]-'A';
	r=y[2]-'A';
	if(((l<3&&r<3)||(l>=3&&r>=3))&&(ans==2))
	{
		ans++;
	}
	if(abs(l-r)==1&&ans==3)
	{
		ans++;
	}
	int i;
	for(i=1;i<=3;i++)
	{
		if(ans>0)
		{
			cout<<'1'<<' ';
			ans--;
		}
		else
		{
			cout<<'0'<<' ';
		}
	}
	if(ans==1)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	return 0;
}
