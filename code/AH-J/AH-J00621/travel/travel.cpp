#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int p1,p2,w1,w2;
	cin>>a>>c>>b>>d;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c[2]=='A'||c[2]=='B'||c[2]=='C'){
		p1=1;
	}
	else p1=2;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		p2=1;
	}
	else p2=2;
	w1=c[2]-'A';
	w2=d[2]-'A';
	if(p1==p2){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(w1==5) w1--;
	if(w2==5) w2--;
	if(abs(w1-w2)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
