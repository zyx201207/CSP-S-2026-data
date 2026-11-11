#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s11,s22;
	int c1,s1,c2,s2;
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(s11=='F')s11='E';
	if(s22=='F')s22='E';
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(min(s11,s22)<='C'&&max(s11,s22)>'C'){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(int(s11-s22))!=1){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
} 
