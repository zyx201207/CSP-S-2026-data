#include<bits/stdc++.h>
using namespace std;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a2,b,b2;
	cin>>a2>>a>>b2>>b;
	if(a2!=b2){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
		if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C') f=1;
		}else if(a[2]=='F'||a[2]=='D'){
			if(b[2]=='F'||b[2]=='D') f=1;
		}if(f){
			cout<<1;
			if((a[2]=='A'&&b[2]=='B') || (b[2]=='A'&&a[2]=='B') || (a[2]=='B'&&b[2]=='C') || (b[2]=='B'&&a[2]=='C') || (a[2]=='F'&&b[2]=='D') || (a[2]=='D'&&b[2]=='F')){
				cout<<1;
			}else cout<<0;
		}else{
			cout<<"00";
			return 0;
		}
	}else cout<<"000";
	return 0;
}
