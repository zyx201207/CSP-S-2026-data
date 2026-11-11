#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
string n1,n2;
char a1,a2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)cout<<1;
	else cout<<0;
	
	n1=s1[0]+s1[1];
	n2=s2[0]+s2[1];
	if(c1==c2&&n1==n2)cout<<1;
	else cout<<0;
	
	a1=s1[2];
	a2=s2[2];
	if(c1==c2&&n1==n2){
		if(a1=='A'||a1=='B'||a1=='C'){
			if(a2=='A'||a2=='B'||a2=='C'){
				cout<<1;
			}else cout<<0;
		}else if(a2=='D'||a2=='F'){
			cout<<1;
		}else cout<<0;
	}
	else cout<<0;
	
	if(c1==c2&&n1==n2){
		if( (a1=='A' && a2=='B') || (a1=='B' && a2=='A') || (a1=='B' && a2=='C') || (a1=='C' && a2=='B') || (a1=='D' && a2=='F') || (a1=='F' && a2=='D') ) {
			cout<<1;
		}else cout<<0;
	}else cout<<0;
	return 0;
}

