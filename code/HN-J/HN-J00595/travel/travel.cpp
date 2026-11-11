#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c1,c2;
	string z1,z2;
	cin >>c1>>z1>>c2>>z2;
	int z1t=0,z2t=0;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	if(z1.substr(0,2)!=z2.substr(0,2)){
		cout<<"1000"<<endl;
		return 0;
	}
	if(68<=((int)z1[2]) && ((int)z1[2])<=70)z1t=1;
	if(68<=((int)z2[2]) && ((int)z2[2])<=70)z2t=1;
	if(z1t!=z2t){
		cout<<"1100"<<endl;
		return 0;
	}
	if(abs(((int)z1[2])-((int)z2[2]))!=1){
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<"1111"<<endl;
	return 0;
}

