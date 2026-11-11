#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a1,a2,b1,b2;
	char c,d;
	scanf("%d %d%c %d %d %c",&a1,&a2,&c,&b1,&b2,&d);
	if(a1==b1)
	{
		cout<<1;
		if(a2==b2)
		{
			cout<<1;
			if((c<='C'&&d<='C') || (c>='D'&&d>='D'))
			{
			
				cout<<1;
				if(int(c-d)==1 || int(c-d)==-1)
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}

