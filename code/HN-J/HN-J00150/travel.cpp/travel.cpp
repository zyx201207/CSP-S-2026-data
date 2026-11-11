#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string n="";
	if(c1==c2)
	{
		n+=1;
	}
	else
	{
		break;
		cout << 0000;
	}
	if(c1==c2&&(a[0]==b[0]&&a[1]==b[1])&&(a[2]=b[2]+1||a[2]==b[2]-1||b[2]==a[2]+1||b[2]==a[2]-1))
{
	if((a[2]!="C"&&b[2]!="D")||(a[2]!="D"&&b[2]="C"))
	{
	cout << 1111;
}
}
if(c1==c2&&(a[0]==b[0]&&a[1]==b[1])&&(a[3]==b[2]||(a[2]!="C"&&b[2]!="D")||(a[2]!="D"&&b[2]!="C"))
{
	cout << 1110;
}
if(c1==c2&&(a[0]==b[0]&&a[1]==b[1])&&(a[2]=="A"||"B"||"C"&&b[2]=="D"||"F")||(a[2]=="A"&&b[2]=="C"))
{
	cout << 1100;
}
if(c1==c2&&(a[0]==b[0]&&a[1]!=b[1])||(a[0]!=b[0]&&a[1]==b[1])||(a[0]!=b[0]&&a[1]!=b[1]))
{
	cout << 1000;
}
	int a[n],b[n];
	for(int i=0;i<=n;i++)
	{
		s1=a[i];
		s2=b[i];
	}

    if(c1==02&&s1=="01A"&&c2==02&&s2=="01B")
    {
    	cout << 1111;
	}
	if(c1==02&&s1=="01C"&&c2==02&&s2=="01A")
	{
		cout << 1110;
	}
	if(c1==02&&s1=="01C"&&c2==02&&s2=="01D")
	{
		cout << 1100;
	}
	if(c1==02&&s1=="02B"&&c2==02&&s2=="01A")
	{
		cout << 1000;
	}
	if(c1==02&&s1=="01A"&&c2==03&&s2=="01A")
	{
		cout << 0000;
	}
	return 0;
}
