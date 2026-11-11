#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0;
string c1,z1,c2,z2;
char g,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	long long x=0,y=0;
	for(int i=0;i<3;i++)
	{
		if(i<2)
		{
			n=n+int(z1[i]-'0')*10;
			m=m+int(z2[i]-'0')*10;
		}
		else 
		{
			x=int(z1[i]-'A');
			y=int(z2[i]-'A');
		}
	}
	if(y<=x)
	{
		int o=y;
		y=x;
		x=o;
	}
	if(c1==c2)cout<<1;
	else cout<<0,s=1;
	if(n==m&&s==0)cout<<1;
	else cout<<0,s=1;
	if(x<3&&y<3&&s==0||x>2&&y>2&&s==0)cout<<1;
	else cout<<0,s=1;
	if(x<=2&&y<=2&&y-x==1&&s==0||x>=3&&y>=3&&s==0)cout<<1;
	else cout<<0;
	return 0;
} 
