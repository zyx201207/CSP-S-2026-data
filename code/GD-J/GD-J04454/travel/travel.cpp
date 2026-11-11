#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]){
		if(a[1]==c[1]){
			if(b[0]==d[0]){
				if(b[1]==b[1]){
					if(b[2]=='A'&&d[2]=='B'){
						cout<<"1111";
					}else if(b[2]=='A'&&d[2]=='C'){
						cout<<"1110";
					}else if(b[2]=='A'&&d[2]=='D'){
						cout<<"1100";
					}else if(b[2]=='A'&&d[2]=='F'){
						cout<<"1100";
					}else if(b[2]=='B'&&d[2]=='A'){
						cout<<"1111";
					}else if(b[2]=='B'&&d[2]=='C'){
						cout<<"1111";
					}else if(b[2]=='B'&&d[2]=='D'){
						cout<<"1100";
					}else if(b[2]=='B'&&d[2]=='F'){
						cout<<"1100";
					}else if(b[2]=='C'&&d[2]=='A'){
						cout<<"1110";
					}else if(b[2]=='C'&&d[2]=='B'){
						cout<<"1111";
					}else if(b[2]=='C'&&d[2]=='D'){
						cout<<"1100";
					}else if(b[2]=='C'&&d[2]=='F'){
						cout<<"1100";
					}else if(b[2]=='D'&&d[2]=='A'){
						cout<<"1100";
					}else if(b[2]=='D'&&d[2]=='C'){
						cout<<"1100";
					}else if(b[2]=='D'&&d[2]=='B'){
						cout<<"1100";
					}else if(b[2]=='D'&&d[2]=='F'){
						cout<<"1111";
					}else if(b[2]=='F'&&d[2]=='A'){
						cout<<"1100";
					}else if(b[2]=='F'&&d[2]=='B'){
						cout<<"1100";
					}else if(b[2]=='F'&&d[2]=='D'){
						cout<<"1111";
					}else{
						cout<<"1100";
					}
				}else{
					cout<<"1000";
				}
			}else{
				cout<<"1000";
			}
		}else{
			cout<<"0000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
