#include<bits/stdc++.h>
using namespace std;
bool q(string x, string y){
	char z=x[2],v=y[2];
	if(z=='A'&&(v=='B'||v=='C')) return true;
	else if(z=='B'&&(v=='A'||v=='C')) return true;
	else if(z=='C'&&(v=='A'||v=='B')) return true;
		else if(z=='F'&&v=='D') return true;
		else if(z=='D'&&v=='F') return true;

	else return false;}
bool w(string x, string y){
	char z=x[2],v=y[2];
	if(z=='A'&&v=='B') return true;
	else if(z=='B'&&(v=='A'||v=='C')) return true;
	else if(z=='C'&&v=='B') return true;
		else if(z=='F'&&v=='D') return true;
		else if(z=='D'&&v=='F') return true;

	else return false;}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(q(b,d)){
				
			cout<<"1";
			if(w(b,d))cout<<"1";
			else cout<<"0";}
			else cout<<"00";
				}
		else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
