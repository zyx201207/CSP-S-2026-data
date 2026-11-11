#include<bits/stdc++.h>
using namespace std;
string c,c1,s,s1;
bool a,b,ab;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<"1";
		ab=1;
	}
	else cout<<"0";
	if(ab&&s1[0]==s[0]&&s1[1]==s[1]){
		cout<<"1";
		b=1;
	}
	else cout<<"0";
	if(b&&(s1[2]<='C'&&s[2]<='C')||(s1[2]>'C'&&s[2]>'C')){
		cout<<"1";
		a=1;
	}
	else cout<<"0";
	if(a&&int(s1[2])-int(s[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
