#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,m,n;
	cin>>x>>y>>m>>n;
	if(x!=m){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(y[0]+y[1]!=n[0]+n[1]){
			cout<<"000";
			return 0;
		} 
		else{
			cout<<1;
			if((y[2]=='A' && n[2]=='B' ) || (y[2]=='B' && n[2]=='C') || (y[2]=='C' && n[2]=='B') || (y[2]=='B' && n[2]=='A') || (y[2]=='D' && n[2]=='F') || (y[2]=='F' && n[2]=='D')){
				cout<<11;
				return 0;
			}
			else if((y[2]<='C' && n[2]>='D') || (y[2]>='D' && n[2]<='C')){
				cout<<"00";
			}
			else{
				cout<<"10";
			}
		}
	}
	return 0;
} 
