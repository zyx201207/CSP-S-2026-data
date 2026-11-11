#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ans="";cin>>a>>b>>c>>d;
	(a==c)?ans+='1':ans+='0';
	string s="",t="";
	for(int i=0;i<2;i++)s+=b[i];
	for(int i=0;i<2;i++)t+=d[i];
	(ans[0]=='1' && s==t)?ans+='1':ans+='0';
	(ans[1]=='1' && ((b[2]>'C')==(d[2]>='C')))?ans+='1':ans+='0';
	int n=b[2]-d[2];
	(ans[2]=='1' && abs(n)==1)?ans+='1':ans+='0';
	cout<<ans;
	return 0;
}
