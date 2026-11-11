#include<bits/stdc++.h> 
using namespace std;
string a;
string b;
string c;
string d;
string ans;
void slo(){
	bool k=0;bool p=0;
	char u=b[0];char y=b[1];
	char i=d[0];char o=d[1];
	char t=b[2];char e=d[2];
	if(u==i&&y==o){
		k=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(k==1){
		if(t=='D'&&e=='F'||t=='A'&&e=='B'||t=='A'&&e=='C'||t=='B'&&e=='C'||e=='D'&&t=='F'||e=='A'&&t=='B'||e=='A'&&t=='C'||e=='B'&&t=='C'){
			p=1;
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(t+1==e&&p==1||t-1==e&&p==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		slo();
	}else{
		cout<<"0000";
	}
	return 0;
}
