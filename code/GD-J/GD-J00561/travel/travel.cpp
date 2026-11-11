#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
string c1,s1,c2,s2;
string wen2s1,wen2s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
//	c1=" "+c1;
//	s1=" "+s1;
//	c2=" "+c2;
//	s2=" "+s2; 
	//1wen
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	//1wen
	
	wen2s1[0]=s1[0];
	wen2s1[1]=s1[1];
	wen2s2[0]=s2[0];
	wen2s2[1]=s2[1];
	//cout<<wen2s2<<' '<<wen2s1<<'\n';
	//2wen 
	if(wen2s1[0]!=wen2s2[0]||wen2s1[1]!=wen2s2[1]){
		cout<<"000";
		return 0;
	}
	else {
		cout<<1;
	}
	//2wen
	ll xr=0,xx=0;
	if(s1[2]=='F'||s1[2]=='D'){
		xr=1;
	}
	else xr=2;
	if(s2[2]=='F'||s2[2]=='D'){
		xx=1;
	}
	else xx=2;
	if(xr!=xx){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	//wen3
	if(s1[2]=='F'||s2[2]=='F')cout<<1;
	else{
		if(s1[2]=='C'){
			if(s2[2]=='B')cout<<1;
			else cout<<0;
		}
		else if(s2[2]=='C'){
			if(s1[2]=='B')cout<<1;
			else cout<<0;
		}
		else if(s1[2]=='B'||s2[2]=='B'){
			cout<<1;
		}
		
	}
	return 0;
} 
