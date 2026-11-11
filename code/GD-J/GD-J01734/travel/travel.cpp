#include<bits/stdc++.h>
using namespace std;
int a,c,n,m,k;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(d[2]=='F')d[2]='E';
	if(b[2]=='F')b[2]='E';
	if(a==c){
		n=1;
		cout<<1;
	}
	else cout<<0;
	if(n==1){
		if(b[0]==d[0]&&b[1]==d[1]){
			m=1;
			cout<<1; 
		}
		else cout<<0;
	}
	else cout<<0;
	if(m==1){
		if(b[2]-'A'<=2&&d[2]-'A'<=2 || b[2]-'A'>2&&d[2]-'A'>2){
			cout<<1;
			k=1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(k==1){
		if(abs((b[2]-'A')-(d[2]-'A'))==1){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
