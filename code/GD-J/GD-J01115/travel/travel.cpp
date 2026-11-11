#include<bits/stdc++.h>
using namespace std;
string n,m,a,b;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>a>>m>>b;
	x+=(a[0]-'0'*10)+a[1]-'0';
	y+=(b[0]-'0'*10)+b[1]-'0';
	if(n==m) {
		cout<<"1";
		if(x==y)
		cout<<"1";
		else{
			for(int i=1;i<=3;i++){
				cout<<"0";
			}
			return 0;
		}
		if(abs(a[2]-b[2])<=3) {
			if(a[2]=='C'&&b[2]=='D'||(a[2]=='D'&&b[2]=='C')){
				cout<<"0";
			}
			else cout<<"1";
		}
		else cout<<"0";	
		if((a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')||a[2]+1==b[2]||a[2]-1==b[2]){
				if(a[2]=='C'&&b[2]=='D'||(a[2]=='D'&&b[2]=='C')){
					cout<<"0";
					return 0;
				}
				else cout<<"1";
		}
		else cout<<"0";
	}
	else {
		for(int i=1;i<=4;i++){
			cout<<"0";
		}
		return 0;
	}
	return 0;
}
