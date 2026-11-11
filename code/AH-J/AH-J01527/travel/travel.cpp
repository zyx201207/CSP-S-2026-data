#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}cout<<"1";
	char a1=s1[0],b1=s1[1],c1=s1[2],a2=s2[0],b2=s2[1],c2=s2[2];
	if(a1!=a2 || b1!=b2){
		cout<<"000";
		return 0;
	}cout<<"1";
	if((c1=='A' && (c2=='B' || c2=='C')) || (c1=='B' && (c2=='A' || c2=='C')) || (c1=='C' && (c2=='B' || c2=='A'))){
		cout<<"1";
		if((c1=='A' && c2=='B') || (c1=='B' && c2=='C') || (c1=='B' && c2=='A') || (c1=='B' && c2=='C')){
			cout<<"1";
			return 0;
		}cout<<"0";
		return 0;
	}
	if((c1=='D' && c2=='F')||(c1=='F' && c2=='D')) cout<<"11";
	return 0;
}
