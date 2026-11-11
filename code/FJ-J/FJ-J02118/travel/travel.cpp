#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,s=0;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i]){
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'||'D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(b[2]=='D'||d[2]=='D'){
		cout<<1;
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
