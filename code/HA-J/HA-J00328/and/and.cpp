#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int c=-1;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	sort(a,a+n,cmp);
	
	for(int i=0;i<m;i++)
	{
		if(m-i!=1)
		{
			c=a[i] and a[i+1];
		}
	}
	
	
	cout << c;
	
	return 0;
}
