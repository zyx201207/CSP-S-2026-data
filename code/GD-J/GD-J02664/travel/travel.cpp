#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	cin>>q>>w>>e>>r;
	string ans;
	if(q==e){
		ans+='1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(w[0]==r[0] && w[1]==r[1]){
		ans+='1';
	}else{
		cout<<"1000";
		return 0;
	}if( (w[2]-1==r[2] && w[2]!='D') || (w[2]+1==r[2] && w[2]!='C') || (w[2]=='A'&& r[2]=='C') || (w[2]=='C' && r[2]=='A')){
		ans+='1';
	}else{
		cout<<"1100";
		return 0;
	}
	if( (w[2]-1==r[2] && w[2]!='D') || (w[2]+1==r[2] && w[2]!='C') ){
		ans+='1';
	}else{
		cout<<"1110";
		return 0;
	}
	cout<<ans;
	return 0;
}
