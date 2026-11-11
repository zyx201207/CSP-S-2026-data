#include<bits/stdc++.h>
using namespace std;
int n,ans1,num,ans2;
int a[200005];
string c[200005];
bool aa()
{
	int ans1=0,num=0;
	int a[20005];
	string x[20005],y[20005];
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=a[i];j++)
		{
			x[i]=c[i];
		}
		
	}
	
	

	for(int i=n;i>=1;i--)
	{
		for(int q=1;q<=a[i];q++)
		{
			y[i]=c[i];
		}
	}

	if(x==y)
		return true;
	else{
		return false;
	}
}

int main()
{
	//freopen ("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	if(aa())
		cout << 0;
		
	
	

	
	
	return 0;
}
