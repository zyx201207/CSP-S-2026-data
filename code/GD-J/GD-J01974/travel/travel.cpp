#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)cout<<'1';
	else cout<<'0';
	if(a==c&&b==d)cout<<'1';
	else cout<<'0';
	if(a==c&&b==d){
		if(e=='A'||e=='B'||e=='C'){
			if(f=='A'||f=='B'||f=='C'){
				cout<<'1';
			}
			else cout<<'0';
		}
		if(e=='D'||e=='F'){
			if(f=='D'||f=='F'){
				cout<<'1';
			}
			else cout<<'0';
		}
	}
	else cout<<'0';
	if(b==d){
		if(e=='A'||e=='B'||e=='C'){
			if(f=='A'||f=='B'||f=='C'){
				if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='B')){
					cout<<'1';
				}
				else cout<<'0';
			}
			else cout<<'0';
		}
		if(e=='D'||e=='F'){
			if(f=='D'||f=='F'){
				cout<<'1';
			}
			else cout<<'0';
		}
	}
	else cout<<'0';
	
	
	return 0;
}
