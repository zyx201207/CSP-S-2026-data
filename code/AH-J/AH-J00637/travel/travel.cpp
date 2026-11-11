#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,p1,s2,p2;
	cin>>s1>>p1>>s2>>p2;
	if(s1!=s2){
		cout<<0<<0<<0<<0;
		return 0;
	}else {
		cout<<1;
	}
	if(p1[0]==p2[0]&&p1[1]==p2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	bool f1=0,f2=0;
	if(p1[2]=='A'||p1[2]=='B'||p1[2]=='C'){
		f1=1;
	}
	if(p2[2]=='A'||p2[2]=='B'||p2[2]=='C'){
		f2=1;
	}
	if(f1==f2){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(f1){
		if((p1[2]=='A'&&p2[2]=='C')||(p1[2]=='C'&&p2[2]=='A')){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<1;
	}
	return 0;
}
