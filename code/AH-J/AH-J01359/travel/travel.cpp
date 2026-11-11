#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			int f=0;
			if(b[2]=='A'&&d[2]=='C'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='C'&&d[2]=='A'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='B'&&d[2]=='A'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='A'&&d[2]=='B'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='C'&&d[2]=='B'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='B'&&d[2]=='C'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='D'&&d[2]=='F'){
				cout<<"1";
				f=1;
			}
			if(b[2]=='F'&&d[2]=='D'){
				cout<<"1";
				f=1;
			}
			if(f==0){
				cout<<"00";
				return 0;
			}
			if(f==1){
				int f1=0;
				if(b[2]=='B'&&d[2]=='A'){
					cout<<"1";
					f1=1;
				}
				if(b[2]=='A'&&d[2]=='B'){
					cout<<"1";
					f1=1;
				}
				if(b[2]=='B'&&d[2]=='C'){
					cout<<"1";
					f1=1;
				}
				if(b[2]=='C'&&d[2]=='B'){
					cout<<"1";
					f1=1;
				}
				if(b[2]=='F'&&d[2]=='D'){
					cout<<"1";
					f1=1;
				}
				if(b[2]=='D'&&d[2]=='F'){
					cout<<"1";
					f1=1;
				}
				if(f1==0){
					cout<<"0";
					return 0;
				}
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
