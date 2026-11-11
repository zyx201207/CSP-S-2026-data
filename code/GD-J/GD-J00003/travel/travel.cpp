#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[10]={0};
	int s,ss;
	vector<int> xd;
	vector<int> yd;
	string c,cc,x,y;
	cin>>c>>x>>cc>>y;
	for(int i=1;i<=x.size();i++)
	{
		if(isdigit(x[i]))
		{
			xd.push_back(x[i]);
		}
		else
		{
			s=x[i]-'0';
		}
	}
	for(int i=1;i<=y.size();i++)
	{
		if(isdigit(y[i]))
		{
			yd.push_back(y[i]);
		}
		else
		{
			ss=y[i]-'0';
		}
	}
	if(c==cc)
	{
		a[1]=1;
	}
	else if(c!=cc)
	{
		cout<<"0000";
		return 0;
	}
	if(xd==yd)
	{
		a[2]=1;
	}
	if((s<=67&&s>=65&&ss<=67&&ss>=65)||(s<=70&&s>67&&ss<=70&&ss>67))
	{
		a[3]=1;
	}
	else if(((ss-s)==1||(s-ss)==1))
	{
		a[4]=1;
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
