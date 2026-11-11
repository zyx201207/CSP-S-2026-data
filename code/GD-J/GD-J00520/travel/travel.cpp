#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	string u="",w="";
	char v,k;
	for(char c:b){
		if(c<='9'&&c>='0') u+=c;
		else v=c;
	}
	for(char c:d){
		if(c<='9'&&c>='0') w+=c;
		else k=c;
	}
	if(a==c&&u==w) cout<<1;
	else cout<<0;
	if(a==c&&u==w&&((((v-'A')<=2)&&((k-'A')<=2)))||(((v-'A')>2)&&((k-'A')>2))) cout<<1;
	else cout<<0;
	if((v-'A')>(k-'A')) swap(v,k);
	if(a==c&&u==w&&((v=='A'&&k=='B')||(v=='B'&&v=='C')||(v=='D'&&v=='E'))) cout<<1;
	else cout<<0;
} 
