#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
string s1,s2,a,b;
int flag;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s1>>a>>s2>>b;
	if(s1==s2) cout<<"1",flag=1;
	else cout<<"0";
	if(flag&&a[0]==b[0]&&a[1]==b[1]) cout<<"1";
	else cout<<"0",flag=0;
	if(flag&&((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D'))) cout<<"1";
	else cout<<"0",flag=0;
	if(flag){
		if(a[2]<='C'&&b[2]<='C'&&abs(a[2]-b[2])==1) cout<<"1";
		else if(a[2]>='D'&&b[2]>='D') cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
//Trick||Treat!
