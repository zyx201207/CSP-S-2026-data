#include <bits/stdc++.h>
using namespace std;

int a,b;
string m,n;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>b>>n;
	if (a==b) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if (m[0]==n[0] && m[1]==n[1]) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}	
	if ((m[2]=='D'&&n[2]=='F') || (m[2]=='F'&&n[2]=='D')) cout<<"11";
	else{
		int x=max(m[2]-'A',n[2]-'A'),y=min(m[2]-'A',n[2]-'A');
		if (x<=2&&y<=2) {
			cout<<"1";
			if ((x-y)==1) {
				cout<<"1";
			}
			else 
				cout<<"0";
			}
		else{
			cout<<"00";
		}
	}
	return 0;
}
