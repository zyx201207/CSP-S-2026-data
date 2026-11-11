#include<bits/stdc++.h>
using namespace std;
long long n,m;
string st1,st2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>n>>st1>>m>>st2;
	if(n!=m){
		cout<<"0000";
		return 0;
	}cout<<1;
	if((st1[0]-'0')*10+st1[1]-'0'!=(st2[0]-'0')*10+st2[1]-'0'){
		cout<<"000";
		return 0;
	}cout<<1;
	if(st1[2]>='A'&&st1[2]<='C'&&st2[2]>='A'&&st2[2]<='C'){
		cout<<1;
		if(abs(st1[2]-st2[2])==1)cout<<1;
		else cout<<0;
	}
	else if(st1[2]>='D'&&st1[2]<='F'&&st2[2]>='D'&&st2[2]<='F')cout<<11;
	else{
		cout<<"00";
		return 0;
	}
	return 0;
} 
