#include<bits/stdc++.h>
using namespace std;
int a,b,m,n;
string x,y;
char i,j;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>x>>b>>y;
	m=(x[0]-'0')*10+(x[1]-'0');
	n=(y[0]-'0')*10+(y[1]-'0');
	i=x[2];
	j=y[2];
	if(a!=b) cout<<"0000";
	else if(m!=n) cout<<1000;
	else if(!((i>='D'&&j>='D')||(i<='C'&&j<='C'))) cout<<1100;
	else if(!(abs((i-'A')-(j-'A'))==1)) cout<<1110;
	else cout<<1111;
	return 0;
}
