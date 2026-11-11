#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,x;
	string n,m;
	cin>>r>>n>>x>>m;
	if(r!=x){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(n[0]==m[0]&&n[1]==m[1]){
			cout<<"1";
			if(((n[2]>='A'&&n[2]<='C')&&(m[2]>='A'&&m[2]<='C'))||((n[2]>='D'&&n[2]<='F')&&(m[2]>='D'&&m[2]<='F'))){
				cout<<"1";
				if(n[2]>='A'&&n[2]<='C'&&m[2]>='A'&&m[2]<='C'){
					if(n[2]-m[2]==1||m[2]-n[2]==1){
						cout<<"1";
						return 0;
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else{
					cout<<"1";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
