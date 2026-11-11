#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f;
int ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
		for(int i=0;i<=1;i++)
			if(s1[i]==s2[i]) ans++;
		if(ans==2) {
			cout<<1;
			if(s1[2]=='A'){
				if(s2[2]=='B'||s2[2]=='C') {
					cout<<1;
					f=1;
					}
				}
				if(s1[2]=='B'){
					if(s2[2]=='A'||s2[2]=='C') {
						cout<<1;
						f=1;
					}
				}
				if(s1[2]=='C'){
					if(s2[2]=='A'||s2[2]=='B') {
						cout<<1;
						f=1;
					
					}
				}
				if(s1[2]=='D'){
					if(s2[2]=='F') {
						cout<<1;
						f=1;
					
					}
				}
				if(s1[2]=='F'){
					if(s2[2]=='D') {
						cout<<1;
						f=1;
					
					}
				}
			}
			else {
				cout<<"000";
				return 0;
			}
		
		if(f==0) {
			cout<<"00";
			return 0;
		}
		else {
			if(s1[2]=='A'){
					if(s2[2]=='B') {
						cout<<1;
						return 0;
					}
				}
			if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C') {
					cout<<1;
					return 0;
					}
				}
			if(s1[2]=='C'){
				if(s2[2]=='B') {
					cout<<1;
					return 0;
					}
				}
			if(s1[2]=='D'){
				if(s2[2]=='F') {
					cout<<1;
					return 0;
					}
				}
			if(s1[2]=='F'){
				if(s2[2]=='D') {
					cout<<1;
					return 0;
					}
				}
		}
		cout<<0;
	}
	else cout<<"0000";
	return 0;
} 
