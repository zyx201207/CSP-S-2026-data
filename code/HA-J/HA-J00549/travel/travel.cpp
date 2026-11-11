#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,cc,s,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	bool b=1;
	for(int i=0;i<2;i++){
		if(s[i]!=ss[i]) b=0;
	}
	if(b==1) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s[2]>'C'&&ss[2]>'C')||(s[2]<='C'&&ss[2]<='C')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	int a=abs(s[2]-ss[2]);
	if(a==1) cout<<"1";
	else cout<<"0";
	return 0;
}
