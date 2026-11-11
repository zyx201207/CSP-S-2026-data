#include <bits/stdc++.h>
using namespace std;
long long r=0,x=0;
string R,X;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>R>>x>>X;
	if(r==x){
		cout<<"1";
		if((R[0]==X[0]) and (R[1]==X[1])){
			cout<<"1";
			if(R[2]>='A' and X[2]>='A' and R[2]<='C' and X[2]<='C'){
				cout<<"1";
				if(R[2]+1==X[2] or R[2]-1==X[2] or R[2]==X[2]+1 or R[2]==X[2]-1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"0";
				cout<<"0";
			}
		}else{
			cout<<"0";
			cout<<"0";
			cout<<"0";
		}
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	return 0;
}
