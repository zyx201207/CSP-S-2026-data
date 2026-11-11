#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	string t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		cout<<1;
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s2[0]==t2[0]&&s2[1]==t2[1]){
		cout<<1;
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	char k1,k2;
	k1=s2[2];
	k2=t2[2];
	if(k1>='A'&&k1<='C'&&k2>='A'&&k2<='C'){
		cout<<1;
	}else if((k1=='D'||k1=='F')&&(k2=='D'||k2=='F')){
		cout<<"11"<<endl;
		return 0;
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if(k1+1==k2||k1-1==k2){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}

