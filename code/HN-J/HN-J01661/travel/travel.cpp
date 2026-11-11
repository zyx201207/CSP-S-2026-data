#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	bool fg=1;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else
	{
		fg=0;
		cout<<0;
	} 
	if(fg && b[0]==d[0] && b[1]==d[1]) cout<<1;
	else
	{
		fg=0;
		cout<<0;
	} 
	if(fg &&(b[2]=='A' && d[2]=='B' || b[2]=='A' && d[2]=='C' || b[2]=='B' && d[2]=='A' || b[2]=='B' && d[2]=='C' || b[2]=='C' && d[2]=='A' || b[2]=='C' && d[2]=='B' || b[2]=='F' && d[2]=='D' || b[2]=='D' && d[2]=='F'))cout<<1;
	else
	{
		fg=0;
		cout<<0;
	} 
	if(fg && b[2]=='D' || b[2]=='B' || d[2]=='B') cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
