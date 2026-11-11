#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1,s2;
	long long c1,c2,s_1,s_2;
	cin>>c1>>s_1>>s1>>c2>>s_2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s_1!=s_2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((s1>'C' && s2<='C') || (s1<='C' && s2>'C')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(s1-s2)>1){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
} 
