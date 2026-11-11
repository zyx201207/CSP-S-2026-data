#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1strt,c2strt,s1strt,s2strt;
	cin>>c1strt>>s1strt>>c2strt>>s2strt;
	if(c1strt==c2strt){
		cout<<1;
		if(s2strt[0]==s1strt[0]&&s2strt[1]==s1strt[1]){
			cout<<1;
			if(s1strt[2]>='A'&&s1strt[2]<='C'&&s2strt[2]<='C'&&s2strt[2]>='A'){
				cout<<1;
				if(s1strt[2]=='B'||s2strt[2]=='B'){
					cout<<1;
				}
				else cout<<0;
			}
			else if((s1strt[2]=='D'||s1strt[2]=='F')&&(s2strt[2]=='D'||s2strt[2]=='F')){
				cout<<1<<1;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
