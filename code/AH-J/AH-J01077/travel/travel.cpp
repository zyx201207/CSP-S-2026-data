#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool pd()
{
	if(a2[2]=='A'&&b2[2]=='B') return true;
	if(a2[2]=='A'&&b2[2]=='C') return true;
	if(a2[2]=='B'&&b2[2]=='C') return true;
	if(a2[2]=='B'&&b2[2]=='A') return true;
	if(a2[2]=='C'&&b2[2]=='B') return true;
	if(a2[2]=='C'&&b2[2]=='A') return true;
	if(a2[2]=='D'&&b2[2]=='F') return true;
	if(a2[2]=='F'&&b2[2]=='D') return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)
	{
		cout<<0<<0<<0<<0<<'\n';
		return 0;
	}
	cout<<1;
	if(a2[0]!=b2[0]||a2[1]!=b2[1])
	{
		cout<<0<<0<<0<<'\n';
		return 0;
	}
	cout<<1;
	if(!pd())
	{
		cout<<0<<0<<'\n';
		
		return 0;
	}
	cout<<1;
	if(abs(int(a2[2])-int(b2[2]))==1) cout<<1;
	else cout<<0;
	cout<<'\n';
	return 0;
}

