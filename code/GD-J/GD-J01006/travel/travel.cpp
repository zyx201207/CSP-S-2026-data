#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
string c1,c2;
char s1,s2;
ll num1,num2,flag1,flag2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>num1>>s1>>c2>>num2>>s2;
	if(s1=='A'||s1=='B'||s1=='C')flag1=1;
	else flag1=2;
	if(s2=='A'||s2=='B'||s2=='C')flag2=1;
	else flag2=2;
	if(c1==c2)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(num1==num2)cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(flag1==flag2)cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1-s2)==1)cout<<1;
	else cout<<0;
	return 0;
}
