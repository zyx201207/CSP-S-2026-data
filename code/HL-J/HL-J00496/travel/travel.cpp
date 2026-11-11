#include<bits/stdc++.h>
using namespace std; 
string a,c;
char x,y,z,n,m,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>y>>z>>c>>n>>m>>k;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(x==n&&y==m){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((z=='F'&&k=='D')||(k=='F'&&z=='D')){
		cout<<1;
	}
	else{
		if(z!='F'&&z!='D'&&k!='F'&&k!='D'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}	
	}
	if(z+1==k||z-1==k){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}