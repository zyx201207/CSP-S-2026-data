#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(b[2]=='A'&&d[2]=='B'){
				cout<<"11";
			}
			else if(b[2]=='B'&&d[2]=='C'){
				cout<<"11";
			}
			else if(b[2]=='D'&&d[2]=='F'){
				cout<<"11";
			}
			else{
				cout<<"10";
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}
