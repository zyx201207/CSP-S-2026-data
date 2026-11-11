#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,n=0,m=0;
    char s11,s12,s13,s21,s22,s23;
    cin>>c1>>s11>>s12>>s13>>c2>>s21>>s22>>s23;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s11!=s21||s12!=s22)
	{
		cout<<"1000";
		return 0;
	}
	if(s13=='D'&&s23=='F')
	{
		n++;
		m++;
	}
	if(s13=='F'&&s23=='D')
	{
		n++;
		m++;
	}
	if(s13=='A'&&s23=='B')
	{
		n++;
		m++;
	}
	if(s13=='B'&&s23=='A')
	{
		n++;
		m++;
	}
	if(s13=='C'&&s23=='B')
	{
		n++;
		m++;
	}
	if(s13=='A'&&s23=='C')
	{
		n++;
	}
	if(s13=='C'&&s23=='A')
	{
		n++;
	}
	cout<<"11"<<n<<m;
	return 0;
}
