#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s,t;
	cin>>n>>s>>m>>t;
	
	//cout<<s[1]<<" ";
	if(n==m){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==t[0]&&s[1]==t[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s[2]<='C'&&s[2]>='A'&&t[2]<='C'&&t[2]>='A')||(s[2]<='E'&&s[2]>='D'&&t[2]<='E'&&t[2]>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs((s[2]-'A')-(t[2]-'A'))==1){
		cout<<1;
	}else cout<<0;
	return 0;
}
