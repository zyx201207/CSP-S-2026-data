//GZ-J00120 ³ÂÜÆåû
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void ss()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool f1=0,f2=0,f3=0,f4=0;
	if(a==c) f1=1;
	if(f1&&b[0]==d[0]&&b[1]==d[1]) f2=1;
	if(f2)
	{
		if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A'))) f3=1;
	}
	if(f1&&f2&&f3)
	{
		if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]=='B')) f4=1;
	}
	if(f1) cout<<1;
	else cout<<0;
	if(f2) cout<<1;
	else cout<<0;
	if(f3) cout<<1;
	else cout<<0;
	if(f4) cout<<1;
	else cout<<0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--) ss();
	return 0;
}
