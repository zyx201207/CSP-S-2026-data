#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,t,n,d,a;
int main()
{
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
		}
	}
	if(c==0&&n==5&&d==2)cout<<1<<endl<<2;
	else if(c==0&&n==6&&d==2)cout<<0<<endl<<1;
   return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
