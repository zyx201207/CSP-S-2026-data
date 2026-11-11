#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) ans+='1';
	else ans+='0';
	if(ans[0]=='1'&&b[0]==d[0]&&b[1]==d[1]) ans+='1';
	else ans+='0';
	if(ans[1]=='1'&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))) ans+='1';
	else ans+='0';
	if(abs(b[2]-d[2])==1&&ans[2]=='1') ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
