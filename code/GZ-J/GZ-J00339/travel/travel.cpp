//GZ-J00339 贵阳市南明区华麟学校 孙君瑞
#include<bits/stdc++.h>
using namespace std;
char c[15];
int cx1,zw1,cx2,zw2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		cin>>c[i];
	}
	cx1=(c[1]-'0')*10+(c[2]-'0');
	zw1=(c[3]-'0')*10+(c[4]-'0');
	cx2=(c[6]-'0')*10+(c[7]-'0');
	zw2=(c[8]-'0')*10+(c[9]-'0');
	if(cx1!=cx2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(zw1!=zw2)
	{
		cout<<"0";
	}
	cout<<"1";
	if((int(c[5])>67&&int(c[10])<=67)||(int(c[5])>67&&int(c[10])<=67))
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(c[5]!='D'||c[10]!='F')
	{
		if(int(c[5])-int(c[10])!=1&&int(c[10])-int(c[5])!=1)
		{
			cout<<"0";
			return 0;
		}
		cout<<"1";
		return 0;
	}
	cout<<"1";
	return 0;
}
