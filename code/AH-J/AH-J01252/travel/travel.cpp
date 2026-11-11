#include<bits/stdc++.h>
using namespace std;
char a[110],b[110];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,y1,i,x2=0,x3=0,y2=0,y3=0;
	string x,y;
	cin>>x1;
	cin>>x;
	cin>>y1;
	cin>>y;
	if(x1==y1) 
	{
		cout<<1;
		for(i=1;i<=3;i++)
		{
			if(x[i]>='0'&&x[i]<='9') 
			x2=x2*10+(x[i]-'0');
			if(y[i]>='0'&&y[i]<='9') 
			y2=y2*10+(y[i]-'0');
			if(x[i]=='A') x3=1;
			else if(x[i]=='B') x3=2;
			else if(x[i]=='C') x3=3;
			else if(x[i]=='D') x3=4;
			else if(x[i]=='F') x3=5;
			if(y[i]=='A') y3=1;
			else if(y[i]=='B') y3=2;
			else if(y[i]=='C') y3=3;
			else if(y[i]=='D') y3=4;
			else if(y[i]=='F') y3=5;
		}
		if(x2==y2)
		{
			cout<<1;
			if(1<=x3&&x3<=3&&1<=y3&&y3<=3)
			{
				cout<<1;
				if(x3==1&&y3==2) cout<<1;
				else if(x3==2&&y3==3) cout<<1;
				else if(x3==2&&y3==1) cout<<1;
				else if(x3==3&&y3==2) cout<<1;
				else cout<<0;
				return 0;
			}
			else if(4<=x3&&x3<=4&&4<=y3&&y3<=5)
			{
				cout<<1<<1;
			}
			else
			{
				cout<<0<<0;
				return 0;
			}
		} 
		else cout<<0<<0<<0;
		return 0;
	}
	cout<<"0000";
	return 0;
}
