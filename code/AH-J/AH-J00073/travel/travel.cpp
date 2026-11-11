#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,m,n;
	bool pd1=0,pd2=0;
	char ch1,ch2; 
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	if(c1==c2) cout<<1,pd1=1;
	else cout<<0;
	if(s1==s2&&pd1) cout<<1,pd2=1;
	else cout<<0;
	m=int(ch1);
	n=int(ch2);
	if(m<=67&&n<=67&&pd2) cout<<1;
	else if(m>67&&n>67&&pd2) cout<<1;
	else cout<<0;
	if(m==n+1&&n!=67&&pd2) cout<<1;
	else if(m==n-1&&m!=67&&pd2) cout<<1;
	else cout<<0;
	return 0;
}
