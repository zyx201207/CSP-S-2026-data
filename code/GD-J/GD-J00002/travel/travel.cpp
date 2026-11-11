#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0] && b[1]==d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((b[2]-'A'<=2 && d[2]-'A'<=2) || (b[2]-'A'>=3 && d[2]-'A'>=3)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(max(b[2]-'A',d[2]-'A')-min(b[2]-'A',d[2]-'A')==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
