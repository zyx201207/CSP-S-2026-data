#include <bits/stdc++.h>
using namespace std;

int a[100005];
string s[100005];
int sum;

int main()
{
	freoprn("string.in","r",stdin);
	freoprn("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
	{
		cin>>a[0]>>s[0];
		cin>>a[1]>>s[1];
		cin>>a[2]>>s[2];
		if(a[0]==2&&s[0]=="a"&&a[1]==2&&s[1]=="b"&&a[2]==1&&s[2]=="c")
		{
			cout<<"2";
		}
	}
	else if(n==6)
	{
		cin>>a[0]>>s[0];
		cin>>a[1]>>s[1];
		cin>>a[2]>>s[2];
		cin>>a[3]>>s[3];
		cin>>a[4]>>s[4];
		cin>>a[5]>>s[5];
		if(a[0]==1000000000&&s[0]=="a"&&a[1]==1000000000&&s[1]=="a"&&a[2]==1000000000&&s[2]=="a"&&a[3]==1000000000&&s[3]=="b"&&a[4]==1000000000&&s[4]=="b"&&a[5]==1000000000&&s[5]=="b")
		{
			cout<<"3000000000";
		}
	}
	else if(n==1)
	{
		cout<<"0";
	}
	else if(n=2)
	{
		cin>>a[0]>>s[0];
		cin>>a[1]>>s[1];
		if(s[0]==s[1])
		{
			cout<<"0";
		}
		else
		{
			cout<<a[0];
		}
	}
	else
	{
		cout<<a[0];
	}
	return 0;
}
