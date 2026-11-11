#include<bits/stdc++.h>
using namespace std;
string sa1,sa2,sb1,sb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>sa1>>sa2>>sb1>>sb2;
	if(sa1==sb1) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(sa2[0]==sb2[0]&&sa2[1]==sb2[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(sa2[2]<='C'&&sb2[2]<='C'||sb2[2]>='D'&&sa2[2]>='D'){
		cout<<1;
	}
	else {
		cout<<0<<0;
		return 0;
	}
	if(sa2[2]==sb2[2]+1||sa2[2]+1==sb2[2]) cout<<1;
	else cout<<0;
	return 0;
} 
