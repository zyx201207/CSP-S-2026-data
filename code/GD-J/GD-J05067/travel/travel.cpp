#include<bits/stdc++.h>
using namespace std;
string zx_R,zw_R,zx_X,zw_X; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>zx_R>>zw_R>>zx_X>>zw_X;
	if(zx_R==zx_X){
		if(zw_R[0]==zw_X[0]&&zw_R[1]==zw_X[1]){
			if(((zw_R[2]>='A'&&zw_R[2]<='C')&&(zw_X[2]>='A'&&zw_X[2]<='C'))||((zw_R[2]>='D'&&zw_R[2]<='F')&&(zw_X[2]>='D'&&zw_X[2]<='F'))){
				if(abs(int(zw_R[2]-zw_X[2]))==1){
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
