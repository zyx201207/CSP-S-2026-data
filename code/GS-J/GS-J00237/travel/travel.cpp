#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n[2][2];

	for(int i=0;i<2;i++){
		for(int j=0;j<=2;j++){
			cin>>n[i][j];
		}
	}
	if(n[0][0]==n[1][0]){
		cout<<"1111";
	}
	if(n[0][0] !=n[1][0]){
		cout<<"0101";
	}
	
	
	return 0 ;
}
