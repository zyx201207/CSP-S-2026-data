#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long che1,che2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>s1>>che2>>s2;
	if(che1==che2){
		cout<<1;
		if(s2[0]+s2[1]-'0'==s1[0]+s1[1]-'0'){
			cout<<1;
			if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A')){
				cout<<1;
				if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
		
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
}
