#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	int n,m;
	string s;
	string d;
	cin>>n>>s>>m>>d;
	if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
		a=1;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		b=1;
	}
	if(s[2]=='D'||s[2]=='F'){
		a=2;
	}
	if(d[2]=='D'||d[2]=='F'){
		b=2;
	}
	if(n==m){
		cout<<1;
		if(s[0]==d[0]&&s[1]==d[1]){
			cout<<1;
			if(a==b){
				cout<<1;
				if(a==2){
					cout<<1;
				}else if(s[2]=='A'&&d[2]=='C'){
					cout<<0;
				}else if(s[2]=='C'&&d[2]=='A'){
					cout<<0;
				}else cout<<1;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
