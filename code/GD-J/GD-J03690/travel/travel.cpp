#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);   
	cin>>x>>a>>y>>b;
	if (x!=y){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if (!(a[0]==b[0] && a[1]==b[1])){
		cout<<"000";
		return 0;
	}
	cout<<1;
	int p=0,q=0;
	if (a[2]=='A' || a[2]=='B' || a[2]=='C'){
		p=1;
	}
	if (b[2]=='A' || b[2]=='B' || b[2]=='C'){
		q=1;
	}
	if (p!=q) {
		cout<<"00";
		return 0;
	}
	cout<<1;
	a=a[0]+a[1];
	b=b[0]+b[1];
	int r=a[2]-'A',u=b[2]-'A';
	if (r+1==u || u+1==r) cout<<1;
	else cout<<0;
} 
