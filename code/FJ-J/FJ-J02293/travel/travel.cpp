#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define N 110510
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	} 
	cout<<'1';
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))
		cout<<'1';
	else 
	{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1)
		cout<<'0';
	else cout<<'1';
	return 0;
}
