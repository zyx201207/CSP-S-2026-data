#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	if(a==d){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==f[0]and s[1]==f[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s[2]<='C' and f[2]<='C')or(s[2]>='D' and f[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s[2]-f[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
