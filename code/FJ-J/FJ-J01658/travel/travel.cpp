#include<bits/stdc++.h>
using namespace std;
//int read()//long long?
//{
//	char c=getchar();
//	int fu=1,res=0;
//	while(c<'0'||c>'9')
//	{
//		if(c=='-') fu=-1;
//		c=getchar();
//	}
//	while('0'<=c&&c<='9')
//	{
//		res=res*10+c-'0';
//		c=getchar();
//	}
//	return res*fu;
//}
//void write(int x)//long long?
//{
//	if(x<0)
//	{
//		putchar('-');
//		x=-x;
//	}
//	if(x<=9)
//	{
//		putchar(x+'0');
//		return;
//	}
//	write(x/10);
//	putchar(x%10+'0');
//	return;
//}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,s1,x2,s2;
	cin>>x1>>s1>>x2>>s2;
	if(x1!=x2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(!(s1[0]==s2[0]&&s1[1]==s2[1]))
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(s1[2]>s2[2]) swap(s1,s2);
	if('A'<=s1[2]&&s1[2]<='C'&&'D'<=s2[2]&&s2[2]<='F')
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(s1[2]=='D'||s1[2]+1==s2[2]) cout<<"1";
	else cout<<0;
	return 0;
}
