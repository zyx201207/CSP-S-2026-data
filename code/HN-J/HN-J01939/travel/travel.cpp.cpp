#include<bits/stdc++.h> 
using namespace std;
#define int long long
	string n,a,b,c,d;
	
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>a>>b>>c>>d;
		if(a==c)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0000";
			return 0;
		}
	if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
		}
		else
		{
			cout<<"000";
			return 0;
		}
		
		if(b[2]>='D'&&d[2]>='D')
		{
			cout<<"11";
			return 0;
		}
		if(b[2]<'D'&&d[2]<'D')
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}	
			if(b[2]=='B'||d[2]=='B')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
			return 0;
		}	
	return 0;
}
