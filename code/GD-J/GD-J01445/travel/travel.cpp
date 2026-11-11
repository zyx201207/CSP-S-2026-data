#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c;
	string n,m;
	cin>>a>>n>>b>>m;
	if(a[0]==b[0] and a[1]==b[1]){
		cout<<1;
		if(n[0]==m[0] and n[1]==m[1]){
			cout<<1;
			if((n[2]=='A' or n[2]=='B' or n[2]=='C')and(m[2]=='A' or m[2]=='B' or m[2]=='C')){
				cout<<1;
				if(abs(n[2]-m[2])==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else if((n[2]=='D' or n[2]=='F')and(m[2]=='D' or m[2]=='F')){
				cout<<1<<1;
				return 0;}
			else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
} 
