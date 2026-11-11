#include <bits/stdc++.h>
using namespace std;
char a[]={'A','B','C','D','F'};
string c1,s1,c2,s2;
int b1[1000005],b2[100005],bs1[1000005],bs2[1000005];
int num1,num2,num3,num4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<1;i++)
	{
		b1[i]=s1[i]+0;
		b2[i]=s2[i]+0;
		
	}
	
	for(int i=1;i>=0;i--)
	{
		num1*=10;
			num1+=b1[i];
		num2*=10;
		num2+=b2[i];
	}
	bool flag=1;
	for(int i=0;i<=1;i++)
	{
		if(!(c1[i]==c2[i])) 
		{
			cout<<0;
			flag=0;
			break;
		}
		
	}
	if(flag) cout<<1;
	if(num1==num2)
		cout<<1;
	else
		cout<<0;
	if(num1==num2 && !(s1[2]>='A' && s1[2]<='C' && s2[2]>='D' && s2[2]<='F'))
		cout<<1;
	else
		cout<<0;
	if(flag && (int(s1[2])==(int(s2[2])+1) ||int(s2[2])==(int(s1[2])+1))   && num1==num2  && !(s1[2]>='A' && s1[2]<='C' && s2[2]>='D' && s2[2]<='F'))
		cout<<1;
	else
		cout<<0;
	return 0;
}
