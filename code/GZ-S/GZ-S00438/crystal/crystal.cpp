//¿Ó’‹Œı  GZ-S00438 
#include<bits/stdc++.h>
using namespace std;
/*
void tx(&d,&n,&m,&a)
{
	if()
	return 0;
}
*/

int main()
{
	freopen(crystal,r,stdin);
	freopen(crystal,w,stdout);
	int n,m,d[10086]={0},a=0,b=0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> d[i];
	}

	for(int i=0;i<n;i++)
	{
		
		a= d[n/2];

		for(int j=i;j<n;j++)
		{
			while(d[j]<a)
			{
				if(m==0)
				{
					break;
				}
				d[j]+=1;
				m-=1;
			}
		}
		if(d[i]==a)
		{
			b+=1;
		}
	}
	cout << b;
	return 0;
 } 
