#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,d,e;
	char c,f; cin>>a>>b>>c>>d>>e>>f;
	if(a==d){
		cout<<"1";
		if(b==e){
			cout<<"1";
			if(c=='A'&&f=='B'){
				cout<<"11";
			}else if(c=='A'&&f=='C'){
				cout<<"10";
			}else if(c=='B'&&f=='C'){
				cout<<"11";
			}else if(c=='D'&&f=='E'){
				cout<<"11";
			}else if(c=='B'&&f=='A'){
				cout<<"11";
			}else if(c=='C'&&f=='A'){
				cout<<"10";
			}else if(c=='C'&&f=='B'){
				cout<<"11";
			}else if(c=='E'&&f=='D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
