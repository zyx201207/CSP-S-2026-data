#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c11=0,c22=0;
	bool f=true;
	for(int i=0;i<c1.size();i++){
		c11*=10;
		c11+=(c1[i]-'0');
	}for(int i=0;i<c2.size();i++){
		c22*=10;
		c22+=(c2[i]-'0');
	}if(c11==c22){
		cout<<1;
	}else{
		cout<<0;
		f=false;
	}c11=0,c22=0;
	for(int i=0;i<s1.size()-1;i++){
		c11*=10;
		c11+=(s1[i]-'0');
	}for(int i=0;i<s2.size()-1;i++){
		c22*=10;
		c22+=(s2[i]-'0');
	}if(f==false){
		cout<<0;
	}else{
		if(c11==c22){
			cout<<1;
		}else{
			cout<<0;
			f=false;
		}
	}if(f==false){
		cout<<0;
	}else{
		if((s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C')||(s1[s1.size()-1]>='D'&&s2[s2.size()-1]>='D')){
			cout<<1;
		}else{
			cout<<0;
			f=false;
		}
	}if(f==false){
		cout<<0;
	}else{
		if((s1[s1.size()-1]=='C'&&s2[s2.size()-1]=='D')||(s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='C')){
			cout<<0;
		}else{
			if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}
