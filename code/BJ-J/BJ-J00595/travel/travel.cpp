#include<bits/stdc++.h>
using namespace std;
int f(char c)
{
	int cnt=c-'A'+1;
	if(cnt==6) cnt--;
	return cnt;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c) 
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int x=(b[0]-'0')*10+(b[1]-'0'),y=(d[0]-'0')*10+(d[1]-'0');
	if(x!=y) 
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	int n=f(b[2]),m=f(d[2]);
	if((n<=3 && m<=3) || (n>3 && m>3)) 
	{
		cout<<1;
		if(abs(n-m)==1) cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
}
