#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<"0000",exit(0);
	string s=b.substr(0,2);
	string s1=d.substr(0,2);
	if(s==s1)cout<<1;
	else cout<<"000",exit(0);
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F')){
		cout<<1;
	}else cout<<"00",exit(0);
	if(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F')cout<<1;
	else if(abs(b[2]-d[2])==1)cout<<1;
	else cout<<"0";
	return 0;
} 
