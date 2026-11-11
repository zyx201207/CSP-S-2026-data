#include<bits/stdc++.h>
using namespace std;
int n,m,cr,cx;
string sr,sx;
bool a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr;
	cin>>cx>>sx;
	if(cr==cx)
	{
		a=1;
		n=(sr[0]-' ')*10+(sr[1]-' ');
		m=(sx[0]-' ')*10+(sx[1]-' ');
		if(n==m)
		{
			b=1;
			if((sr[2]<='C'&&sx[2]<='C')||(sr[2]>='D'&&sx[2]>='D'))
			{
				c=1;
				if(sr[2]-sx[2]==1||sr[2]-sx[2]==-1)
					d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	
	return 0;
} 
