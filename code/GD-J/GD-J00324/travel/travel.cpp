#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string x="",y="",a="",b="";
	cin>>a>>x>>b>>y;
	string s="";
	if(a==b) s+="1";
	else s+="0";
	if((x[0]==y[0] && x[1]==y[1]) && s[0]=='1') s+="1";
	else s+="0";
	if(((x[2]>='D' && x[2]<='E' && y[2]>='D' && y[2]<='E') || (x[2]>='A' && x[2]<='C' && y[2]>='A' && y[2]<='C')) && s[1]=='1') s+="1";
	else s+="0";
	if((int(x[2])-int(y[2])==1 || int(y[2])-int(x[2])==1) && s[2]=='1') s+="1";
	else s+="0";
	cout<<s;
	return 0; 
}
