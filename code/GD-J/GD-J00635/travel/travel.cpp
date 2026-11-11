#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int p=4;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		p=0;
	}
	if(p==4){
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			p=1;
		}
	}
	if(p==4){
		if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C')){
			p=2;
		}
	}
	if(p==4){
		if(abs(s1[2]-s2[2])!=1){
			p=3;
		}
	}
	for(int i=1;i<=p;i++){
		cout<<1;
	}
	for(int i=1;i<=4-p;i++){
		cout<<0;
	}
	return 0;
} 
