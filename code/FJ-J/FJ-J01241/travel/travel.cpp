#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w,e,r;
	cin>>q>>w>>e>>r;
	if(q==e){
		cout<<1;
	}
	else{
	    cout<<"0000";
		return 0;	
	}
	if(w[0]==r[0]&&w[1]==r[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((w[2]=='A'||w[2]=='B'||w[2]=='C')&&(r[2]=='A'||r[2]=='B'||r[2]=='C'))){
		if(r[2]=='B'||w[2]=='B'){
			cout<<11;
			return 0;
		}
		else{
			cout<<10;
			return 0;
		}
	}
	else if(((w[2]=='F'||w[2]=='D')&&(r[2]=='D'||r[2]=='F'))){
		cout<<11;
		return 0;
	}
	else cout<<"00";
	return 0;
} 
