#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=1;
	}else{
		cout<<0;
	}
	
	if(a&&s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			b=1;
	}else{
		cout<<0;
	}
	if(b&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))){
		cout<<1;
			c=1;
	}else{
		cout<<0;
	}
	if(c&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
