#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;
int a[N];

string ejz(int n)
{
	string num;
	int i=0;
	while(n/2==0)
	{
		num+=n%2;
		n/=2;
	}
	return num;
}
bool cmp(int x,int y)
{
	string xs,ys;
	xs=ejz(x);
	ys=ejz(y);
	int x1=xs.size();
	int y1=ys.size();
	if(x1<y1)
	{
		return x<y;
	}
	else if(x1>y1)
	{
		return x>y;
	}
	else
	{
		for(int i=0; i<=x1; i++)
		{
			if(ejz(x)[i]>ejz(y)[i])
			{
				return x<y;
			}
			else
			{
				return x>y;
			}
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	cout<<a[n-m];
	return 0;
}
