#include <bits/stdc++.h>
using namespace std;
int n,nt,m,mt;
char d,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>nt>>d>>m>>mt>>b;
	if(n==m)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	
	if(nt==mt)cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}
	
	if(d=='F'&&b=='D'||d=='D'&&b=='F')cout<<11;
	if(d!='F'&&b!='D'||d!='D'&&b!='F'){
		if(d=='A'&&b=='B'||d=='B'&&b=='A'){
			cout<<11;
		}else if(d=='A'&&b=='C'||d=='C'&&b=='A'){
			cout<<10;
		}else if(d=='B'&&b=='C'||d=='C'&&b=='B'){
			cout<<11;
		}
		
	}
	if(d=='F'&&b!='D')cout<<0<<0;
	if(d!='F'&&b=='D')cout<<0<<0;
	return 0;
} 
