//GZ-J00456
//贵阳市白云区华师一学校 
//廖博亚 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int bigflag=0;
	if(a==c)
	{
		cout<<1;
		bigflag=1;
	}
	else cout<<0;
	int flag=0;
	int pa=(b[0]-'0')*10+b[1]-'0';
	int pb=(d[0]-'0')*10+d[1]-'0';
	if(pa==pb&&bigflag==1)
	{
		flag=1;
		cout<<1;
	}
	else cout<<0;
	int flag2=0;
	if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'&&flag==1&&bigflag==1) 	
	{
		cout<<1;
		flag2=1;
	}
	else if('D'<=b[2]&&b[2]<='E'&&'D'<=d[2]&&d[2]<='E'&&flag==1&&bigflag==1)
	{
		cout<<1;
		flag2=1;
	}
	else cout<<0;
	if(abs(b[2]-d[2])==1&&flag==1&&flag2==1&&bigflag==1) cout<<1;
	else cout<<0; 
 } 
