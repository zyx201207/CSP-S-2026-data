#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[9],b[9],c[9],d[9];
	cin>>a[1]>>a[2]>>b[1]>>b[2]>>b[3]>>c[1]>>c[2]>>d[1]>>d[2]>>d[3];
	if(a[1]==c[1]&&a[2]==c[2]) cout<<1;
	else{
		cout<<0;
		return 0;
	}
	if(b[1]==d[1]&&b[2]==d[2]){
		cout<<1;
		if(b[3]=='A'||b[3]=='B'||b[3]=='C'){
			if(d[3]=='A'||d[3]=='B'||d[3]=='C'){
				cout<<1;
				if(b[3]=='A'&&d[3]=='B'){
					cout<<1;
				}else if(b[3]=='B'&&d[3]=='C'){
					cout<<1;
				}else if(b[3]=='C'&&d[3]=='B'){
					cout<<1;
				}else if(b[3]=='B'&&d[3]=='A'){
					cout<<1;
				}else if(b[3]=='A'&&d[3]=='C'){
					cout<<0;
				}else if(b[3]=='C'&&d[3]=='A'){
					cout<<0;
				}
			}else{
				cout<<00;
			}
		}else{
			if(c[3]=='D'||c[3]=='E'){
				cout<<11;
			}
			else cout<<00;
		}
	}else cout<<0;
	return 0;
} 
