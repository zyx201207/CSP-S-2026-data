#include<bits/stdc++.h>
using namespace std;
string n,m;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	if(n==m){
		if(x[0]==y[0]&&x[1]==y[1]){
			if(x[2]<='C'&&y[2]<='C'||x[2]>'C'&&y[2]>'C'){
				if(x[2]-y[2]==1||y[2]-x[2]==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
