#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		ll ss1,ss2;
		ss1=ss2=0;
		ss1=(s1[0]-'0')*10+(s1[1]-'0');
		ss2=(s2[0]-'0')*10+(s2[1]-'0');
		if(ss1==ss2){
			cout<<1;
			char a,b;
			a=s1[2];
			b=s2[2];
			if((a<='C' && b<='C') || (a>='D' && b>='D')){
				cout<<1;
				if((a=='A' && b=='B') || (a=='B' && b=='A') || (a=='A' && b=='C') || (a=='C' && b=='A') || (a=='D' && b=='F') || (a=='F' && b=='D')){
					cout<<1;
				}
				else {
					cout<<0;
				}								
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
} 
