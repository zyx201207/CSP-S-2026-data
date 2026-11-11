#include<bits/stdc++.h> 
using namespace std;
string s1;
string s2;
char a[1000010];
char b[1000010];
char c[1000010];
char d[1000010];
int main()
{
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	char c1,c2,cnt=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	for(int i=1;i<=3;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			a[i]=s1[i];
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			b[i]=s2[i];
		}
	}
	for(int i=1;i<=2;i++)
	{
		if(a[i]==b[i])
		{
			cnt++;
		}
	}
	if(cnt==2&&c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}  
	for(int i=1;i<=3;i++)
	{
		if(s1[i]>='A'&&s1[i]<='Z')
		{
			c[i]=s1[i];
		}
	}
	for(int i=1;i<=3;i++)
	{
		if(s2[i]>='A'&&s2[i]<='Z')
		{
			d[i]=s2[i];
		}
	}
	if(c[3]<='C'&&d[3]<='C'&&c1==c2&&cnt==2||c[3]>='D'&&d[3]>='D'&&c1==c2&&cnt==2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	if(c[3]==d[3]-'1'+'2'||c[3]==d[3]+'1'-'2')
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	} 
	return 0;
}
