#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char a1,a2,a3,b1,b2,b3,tmp;
	cin>>a>>a1>>a2>>a3>>tmp>>b>>b1>>b2>>b3;

	if(a==b)
	{
		cout<<1;
		if(a1==b1&&a2==b2)
		{
			cout<<1;
			if(((a3=='A'||a3=='B'||a3=='C')&&(b3=='A'||b3=='B'||b3=='C'))||((a3=='E'||a3=='F')&&(b3=='E'||b3=='F')))
			{
				cout<<1;
				if((a3-b3==1||a3-b3==-1)&&!((a3=='C'&&b3=='D')||(a3=='D'&&b3=='C'))){
					cout<<1;
				}else cout<<0;
			}
			else cout<<"00";	
		}
		else cout<<"000";
		}
	else cout<<"0000";
	return 0;
}

