#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
string c1,s1,c2,s2;
signed main(){
	fre("travel");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string ss1=s1.substr(0,2),
		ss2=s2.substr(0,2);
		if(ss1==ss2){
			if((s1[2]>'C')==(s2[2]>'C')){
				if(abs(s1[2]-s2[2])==1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

