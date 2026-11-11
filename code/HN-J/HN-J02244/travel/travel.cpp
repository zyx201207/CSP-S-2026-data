#include<bits/stdc++.h>
using namespace std;
struct st{
	string c;
	string z;
};
int main(){
	bool is{true};
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	st a[3];
	for(int i=1;i<=2;i++){
		cin>>a[i].c>>a[i].z;
	}
	if(a[1].c==a[2].c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(a[1].z[i]==a[2].z[i]){
			is=true;
		}
		else{
			cout<<"000";
			is=false;
			return 0;
		}
	}
	if(is){
		cout<<"1";
	}
	if((a[1].z[2]=='D'||a[1].z[2]=='F')&&(a[2].z[2]=='D'||a[2].z[2]=='F')){
		cout<<"11";
		return 0;
	}
	else{
		if(a[1].z[2]=='D'||a[1].z[2]=='F'){
			cout<<"00";
			return 0;
		}
		if(a[2].z[2]=='D'||a[2].z[2]=='F'){
			cout<<"00";
			return 0;
		}
		else{
			if(a[1].z[2]=='B'||a[2].z[2]=='B'){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"10";
				return 0;
			}
		}
	}
	return 0;
} 
