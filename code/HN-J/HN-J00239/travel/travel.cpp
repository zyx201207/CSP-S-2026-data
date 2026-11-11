#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int p,p1,p2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		p=1;
	}
	else cout<<0;
	if(p==1&&b[0]==d[0]&&b[1]==d[1])
	{
		cout<<1;
		p1=1;
	 } 
	else cout<<0;
	if(p==1&&p1==1&&(b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')||(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
	{
		cout<<1;
		p2=1;
	 }  
	else cout<<0;
	if(p==1&&p1==1&&p2==1&&b[2]=='A'&&d[2]=='B'||p==1&&p1==1&&p2==1&&d[2]=='A'&&b[2]=='B') cout<<1;
	else if(p==1&&p1==1&&p2==1&&b[2]=='B'&&d[2]=='C'||p==1&&p1==1&&p2==1&&d[2]=='B'&&b[2]=='C') cout<<1;
	else if(p==1&&p1==1&&p2==1&&b[2]=='D'&&d[2]=='F'||p==1&&p1==1&&p2==1&&d[2]=='D'&&b[2]=='F') cout<<1;
	else cout<<0;
//	cout<<" "<<p<<" "<<p1<<" "<<p2;
	return 0;
 } 
