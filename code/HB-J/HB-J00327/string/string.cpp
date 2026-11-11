#include<bits/stdc++.h>
using namespace std;
long long  n,a[200001],m;
char c[21364847],x,d[21364847];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int aaa=0;
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cin >> x;
		for(int i=aaa+1;i<=aaa+x;i++)
		{
				c[i]=x;
		}	
		aaa+=a[i];
	}	
	for(int i=1;i<=aaa;i++)
	d[i]=c[aaa-i+1];
	for(int i=1;i<=aaa;i++)
	{
		if(c[i]!=d[i])
			m++;
	}	
	cout << m/2;
	return 0;
}	
