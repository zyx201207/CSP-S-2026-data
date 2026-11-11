#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int s,k,l,H,J;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}for(int i=0;i<b.size()-1;i++){
		if(b[i]==d[i]){
			s++;
		}
	}
	if(s==2&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[2]=='F'||b[2]=='D'){
		k=1;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		k=2;
	}
	if(d[2]=='F'||d[2]=='D'){
		l=1;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		l=2;
	}
	if(a==c&&s==2&&k==l){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[2]=='A'){
		H=1;
	}
	if(b[2]=='B'){
		H=2;
	}
	if(b[2]=='C'){
		H=3;
	}
	if(b[2]=='D'){
		H=5;
	}
	if(b[2]=='F'){
		H=6;
	}
	if(d[2]=='A'){
		J=1;
	}
	if(d[2]=='B'){
		J=2;
	}
	if(d[2]=='C'){
		J=3;
	}
	if(d[2]=='D'){
		J=5;
	}
	if(d[2]=='F'){
		J=6;
	}
	if(a==c&&s==2&&k==l&&abs(H-J)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
//Trick||Treat!
