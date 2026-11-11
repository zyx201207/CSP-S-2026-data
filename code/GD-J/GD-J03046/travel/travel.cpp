#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int pai1=0;
	int pai2=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		pai1=1;
	}
	else pai1=2;
	
	
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		pai2=1;
	}
	else pai2=2;
	
	
	if(a==c){
		cout<<1;
	}
	else cout<<0;
	
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	
	else cout<<0;
	
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&pai1==pai2){
		cout<<1;
	}
	else cout<<0;
	
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&pai1==pai2&&((b[2]-1==d[2])||(b[2]+1==d[2]))){
		cout<<1;
	}
	
	else cout<<0;
	return 0;
}
