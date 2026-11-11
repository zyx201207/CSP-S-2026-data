#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,a,b;
	long long k,p;
	cin>>n>>m>>a>>b;
	if(n==a){
		cout<<"1";
		if(m[0]==b[0]&&m[1]==b[1]){
			cout<<"1";
			k=m[2]-'A';
			p=b[2]-'A';
			if(k+p==7){
				cout<<"11";
			}
			else if(k+p<=3){
				cout<<"1";
				if(k==1||p==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
