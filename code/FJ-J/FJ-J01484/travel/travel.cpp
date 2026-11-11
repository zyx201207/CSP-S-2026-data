#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	string cp;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	node r,x;
	cin>>r.n>>r.cp;
	cin>>x.n>>x.cp;
	if(r.n==x.n){
		cout<<1;
		if(r.cp[0]==x.cp[0]&&r.cp[1]==x.cp[1]){
			cout<<1;
			if((r.cp[2]=='A'&&x.cp[2]=='B')||(r.cp[2]=='A'&&x.cp[2]=='C')||(r.cp[2]=='B'&&x.cp[2]=='A')||(r.cp[2]=='B'&&x.cp[2]=='C')||(r.cp[2]=='C'&&x.cp[2]=='A')||(r.cp[2]=='C'&&x.cp[2]=='B')||(r.cp[2]=='D'&&x.cp[2]=='F')||(r.cp[2]=='F'&&x.cp[2]=='D')){
				cout<<1;
				if((r.cp[2]=='A'&&x.cp[2]=='B')||(r.cp[2]=='B'&&x.cp[2]=='A')||(r.cp[2]=='B'&&x.cp[2]=='C')||(r.cp[2]=='C'&&x.cp[2]=='B')||(r.cp[2]=='D'&&x.cp[2]=='F')||(r.cp[2]=='F'&&x.cp[2]=='D')){
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
	
	return 0;
}
