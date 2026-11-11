#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
string c1,s1,c2,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000",exit(0);
	if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000",exit(0);
	char a=s1[2],b=s2[2];
	if(a=='F')a='E';
	if(b=='F')b='E';
	if(!((a<='C'&&b<='C')||(a>='D'&&b>='D')))cout<<"1100",exit(0);
	if(abs(a-b)!=1)cout<<"1110",exit(0);
	cout<<"1111";
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	no TLE
	ll _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
