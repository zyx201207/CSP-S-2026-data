#include<iostream>
using namespace std;
int a[50][3],cnt1,cnt2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	cnt1=int(c2[0]-'0')*10+int(c2[1]-'0');
	cnt2=int(c4[0]-'0')*10+int(c4[1]-'0');
	if(c1==c3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c3&&cnt1==cnt2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c1==c3&&cnt1==cnt2)&&((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='A')||(c2[2]=='A'&&c4[2]=='C')||(c2[2]=='C'&&c4[2]=='A')||(c2[2]=='C'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='C')||(c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c1==c3&&cnt1==cnt2)&&((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='A')||(c2[2]=='C'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='C')||(c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
