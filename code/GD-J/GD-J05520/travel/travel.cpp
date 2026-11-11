#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	char a1,b1,b2,a2;
	cin>>a1>>a2>>s1>>b1>>b2>>s2;
	if(a1==b1&&a2==b2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	int x=(s1[0]-'0')*10+(s1[1]-'0');
	int y=(s2[0]-'0')*10+(s2[1]-'0');
	char a=s1[2],b=s2[2];
	int z[10][30]={};
	z[int(a-'A')][x]=1;
	z[int(b-'A')][y]=1;
	int f1=0,f2=0,f3=0;
	int cnt=0;
	if(x==y)f1=1;
	cnt=0;
	for(int i=0;i<3;i++)
	{
		if(z[i][x]==1)cnt++;
	}
	if(cnt==2)f2=1;
	cnt=0;
	for(int i=4;i<6;i++)
	{
		if(z[i][x]==1)cnt++;
	}
	if(cnt==2)f2=1;
	if(z[0][x]==1&&z[1][x]==1||z[1][x]==1&&z[2][x]==1||z[4][x]==1&&z[5][x]==1)f3=1;
	cout<<f1<<f2<<f3;
	return 0;
}
