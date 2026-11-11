//¿Ó’‹Œı  GZ-S00438 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen(migrate,r,stdin);
	freopen(migrate,w,stdout);
	int c,t,n,d,m[10086]={0};
	cin >> c >>t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> d;
		int x[n-1]={0},a;
		for(int j=0;j<n;j++)
		 {
		 	cin >> a;
		 	x[j]=a;
		 }
		if(a-x[0]<=n+d-1)
		{
			m[i]=n-d-d+1;
		}
		
		else
		{
			m[i]=n/2-d;
		}
	}
	for(int i=0;i<t;i++)
	{
		if(m[i]<0)
		{
			cout << 0 <<'\n';
		}
		else
		{
			cout << m[i] << '\n';
		}
		
	}
	
	return 0;
}
