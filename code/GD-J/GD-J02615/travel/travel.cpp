#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char ch;
int n,m;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1;
	cin>>ch,n=n*10+(ch-'0');
	cin>>ch,n=n*10+(ch-'0');
	cin>>a;
	
	cin>>s2;
	cin>>ch,m=m*10+(ch-'0');
	cin>>ch,m=m*10+(ch-'0');
	cin>>b;
	if(s1==s2) {
		cout<<1;
		if(n==m){
			cout<<1;
			if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
				cout<<1;
				if(a-b==1||b-a==1) 
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
