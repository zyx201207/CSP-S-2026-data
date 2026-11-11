#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c)cout<<1;
	else cout<<0;
	if (a==c&&b[0]+b[1]==d[0]+d[1])cout<<1;
	else cout<<0;
	if (a==c&&b[0]+b[1]==d[0]+d[1]&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')))cout<<1;
	else cout<<0;
	if (a==c&&b[0]+b[1]==d[0]+d[1]){
		if (b[2]=='A'&&d[2]=='B')cout<<1;
		else if (b[2]=='B'&&d[2]=='A')cout<<1;
		else if (b[2]=='B'&&d[2]=='C')cout<<1;
		else if (b[2]=='C'&&d[2]=='B')cout<<1;
		else if (b[2]=='D'&&d[2]=='F')cout<<1;
		else if (b[2]=='F'&&d[2]=='D')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	cout<<endl;
	return 0;
}
