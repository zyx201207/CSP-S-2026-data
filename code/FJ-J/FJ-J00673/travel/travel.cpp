#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string s,k,ss,kk;
	cin>>s>>k>>ss>>kk;
	int a=0,b=0,c=0,d=0;
	if(s==ss)
	{
		a=1;
		if(k[0]==kk[0]&&k[1]==kk[1])
		{
			b=1;
			if(k[2]<='C'&&kk[2]<='C'||k[2]>='D'&&kk[2]>='D')
			{
				c=1;
				if(k[2]+1==kk[2]||k[2]-1==kk[2])d=1; 
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
