#include<bits/stdc++.h>
using namespace std;
string s1,w1,s2,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>w1>>s2>>w2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	} 
	if(w1[0]!=w2[0]||w1[1]!=w2[1]){
		cout<<1000;
		return 0;
	}
	char c1=w1[2],c2=w2[2];
	if(c1<c2) swap(c1,c2);
	if(c1-c2==1){
		if(c1!='D') cout<<1111;
		else cout<<1100;
	} 
	else{
		if(c1=='C'&&c2=='A') cout<<1110;
		else cout<<1100;
	}
	return 0;
}
