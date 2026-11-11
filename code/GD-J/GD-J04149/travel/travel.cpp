#include<bits/stdc++.h> 
#define int long long 
const int N=1e5+21;
using namespace std;
int n,a[N];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(a=='A'||a=='B'||a=='C')
	{
		if(b=='A'||b=='B'||b=='C')
		cout<<1;
		else if(b=='D'||b=='E'){
			cout<<"00";
			return 0; 
		}
	}
	else {
		if(b=='D'||b=='E')
		{
			cout<<1;
		}
		else {cout<<"00";return 0;}
	}
	if(b==a+1||b==a-1){
		cout<<1;
	}
	else cout<<0;
	return 0;
 } 
