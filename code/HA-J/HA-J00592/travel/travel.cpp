#include <bits/stdc++.h>
using namespace std;
int c,s;
string ss,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>s>>ss;
	if(c == s){
		cout<<1;
		if(cc[0] == ss[0]&&cc[1]==ss[1]){
			cout<<1;
		if((cc[2]<='C'&&ss[2]<='C')||(cc[2]>'C'&&ss[2]>'C')){
			cout<<1;
		}else{
			cout<<0;
		}
		if(int(abs(ss[2]-cc[2]))==1&&(cc[2]!='C'&&ss[2]!='D')&&(cc[2]!='D'&&ss[2]!='C')){
			cout<<1;	
		}else{
			cout<<0;
		}	
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
