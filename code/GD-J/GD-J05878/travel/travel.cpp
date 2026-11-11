#include<bits/stdc++.h>
using namespace std;
long long q,w,r,t;
char n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>n>>r>>t>>m;
	if(q==r){
		cout<<1;
		if(w==t){
			cout<<1;
		if(n=='D'&&m=='F'){
			cout<<11;
		}else if(n=='F'&&m=='D'){
			cout<<11;
		}else if(n=='A'&&m=='B'){
			cout<<11;
		}else if(n=='B'&&m=='A'){
			cout<<11;
		}else if(n=='A'&&m=='C'){
			cout<<10;
		}else if(n=='C'&&m=='A'){
			cout<<10;
		}else if(n=='C'&&m=='B'){
			cout<<11;
		}else if(n=='B'&&m=='C'){
			cout<<11;
		}else{
			cout<<"00";
		}
		}else{
			cout<<"000";
		}
		}else{
			cout<<"0000";
		}
		return 0;
} 
