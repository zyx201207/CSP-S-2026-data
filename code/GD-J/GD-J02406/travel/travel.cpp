#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)
	{
		ans+='1';
		if(rs[0]==xs[0]&&rs[1]==xs[1])
		{
			ans+='1';
			if((rs[2]=='A'||rs[2]=='B'||rs[2]=='C')&&(xs[2]=='A'||xs[2]=='B'||xs[2]=='C'))
			{
				ans+='1';
				if(xs[2]-1==rs[2]||rs[2]-1==xs[2])
					ans+='1';
				else
					ans+='0';
			}
			else
			{
				if((rs[2]=='D'||rs[2]=='F')&&(xs[2]=='D'||xs[2]=='F'))
					ans+="11";
				else
					ans+="00";
			}
		}
		else
			ans+="000";
	}
	else
		ans="0000";
	cout<<ans;
	return 0;
} 
