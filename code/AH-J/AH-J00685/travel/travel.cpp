#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1!=t1){
		cout<<"0000";
	}else if(!(s2[0]==t2[0]&&t2[1]==s2[1])){
		cout<<"1000";
	}else if(s2[2]>'C'&&t2[2]>'C'){
		cout<<"1111";
	}else if(s2[2]<='C'&&t2[2]<='C'){
		char a=s2[2],b=t2[2];
		if(a+1==b||a-1==b){
			cout<<"1111";
		}else{
			cout<<"1110";
		}
	}else{
		cout<<"1100";
	}
	return 0;
}
