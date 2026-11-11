#include<bits/stdc++.h>
using namespace std;
#define ll long long
string Cyrene="0000";
void solve()
{
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		Cyrene[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			Cyrene[1]='1';
			if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))
			{
				Cyrene[2]='1';
				if(s2[2]=='B') Cyrene[3]='1';
			}
			if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
			{
				Cyrene[2]='1';
				Cyrene[3]='1';
			}
			if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))
			{
				Cyrene[2]='1';
				if(s2[2]=='B') Cyrene[3]='1';
			}
			if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))
			{
				Cyrene[2]='1';
				Cyrene[3]='1';
			}
		}
	}
	cout<<Cyrene;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;	
} 
