#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long ax(char a){
	if(a>='A' && a<='C'){
		return 1;
	}
	else if(a>='D' && a<='F'){
		return 2;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	long long p=ax(s1[s1.size()-1]);
	long long q=ax(s2[s2.size()-1]);
	if(p==q){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	long long x=s1[s1.size()-1];
	long long y=s2[s2.size()-1];
	if(abs(x-y)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
