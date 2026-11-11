#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ans="";
	cin>>a>>b>>c>>d;
	if(a==c) ans+="1";
	else ans+="0";
	if(ans=="1"&&b[0]==d[0]&&b[1]==d[1]) ans+="1";
	else ans+="0";
	if(ans=="11"&&b[0]==d[0]&&b[1]==d[1]&&b[2]<='C'&&d[2]<='C'||ans=="11"&&b[0]==d[0]&&b[1]==d[1]&&b[2]>='D'&&d[2]>='D') ans+="1";
	else ans+="0";
	if(ans=="111"&&abs(int(b[2]-'A')-int(d[2]-'A'))==1) ans+="1";
	else ans+="0";
	cout<<ans;
	return 0;
}
