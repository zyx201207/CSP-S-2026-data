#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else cout<<"0000",exit(0);
	
	if(b[0]+b[1]==d[0]+d[1]){
		cout<<1;
	}
	else cout<<"000",exit(0);
	
	
	if((b[2]<='C' and d[2]<='C') or (b[2]>='D' and d[2]>='D')){
		cout<<1;
	}
	else   cout<<"00",exit(0);
	
	if((b[2]=='A' and d[2]=='B') or (b[2]=='B' and d[2]=='A') or (b[2]=='B' and d[2]=='C') or (b[2]=='C' and d[2]=='B') or (b[2]=='D' and d[2]=='F') or (b[2]=='F' and d[2]=='D')) cout<<1;
	else cout<<"0",exit(0); 
} 
