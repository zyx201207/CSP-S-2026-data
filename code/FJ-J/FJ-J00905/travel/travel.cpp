#include<iostream>
using namespace std;
int f[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string z1="",z2="";
	z1+=s1[0];
	z1+=s1[1];
	z2+=s2[0];
	z2+=s2[1];
	if(c1==c2) 
	{
	cout<<1;
	f[1]=1;	
}
	else cout<<0;
	if(z1==z2&&f[1]==1) 
	{
		cout<<1;
		f[2]=1;
	}
	else cout<<0;
	int a1,a2;
	a1=s1[2]-'A';
	a2=s2[2]-'A';
	if(((a1>=3&&a2>=3)||(a1<3&&a2<3))&&f[2]==1) 
	{
		cout<<1;
		f[3]=1;
	}
	else cout<<0;
	if((a1-a2==1||a2-a1==1)&&f[3]==1) cout<<1;
	else cout<<0;
	return 0;
}
