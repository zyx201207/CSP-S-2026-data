#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string a,b,c,d,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+='1';
		int x=b[0]-'0',y=d[0]-'0';
		x*=10,y*=10;
		x+=b[1]-'0',y+=d[1]-'0';
		if(x==y)
		{
			ans+='1';
			char l=b[2],r=d[2];
			if(l>='A'&&l<='C'&&r>='A'&&r<='C')
				ans+='1';
			else if(l>='D'&&l<='F'&&r>='D'&&r<='F')
				ans+='1';
			else
				ans+='0';
			
			
			if((l=='A'&&r=='B')||(l=='B'&&r=='A'))
				ans+='1';
			else if((l=='C'&&r=='B')||(l=='B'&&r=='C'))
				ans+='1';
			else if( (l=='D'&&r=='F')||(l=='F'&&r=='D'))
				ans+='1';
			else
				ans+='0';
		}
		else
			ans+="000";
	}
	else
		ans="0000";
	cout<<ans;
	
}
//Trick||Treat!
