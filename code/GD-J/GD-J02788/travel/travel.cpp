#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],c3[5],c4[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1[1]!=c3[1]||c1[0]!=c3[0]){
		cout<<"0000";//02 01A 01 01B
	}else if(c2[0]!=c4[0]||c2[1]!=c4[1]){
		cout<<"1000";//02 01A 02 02C
	}else if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')^(c4[2]=='A'||c4[2]=='B'||c4[2]=='C')){
		cout<<"1100";//02 01D 02 01C
	}else if(abs(c2[2]-c4[2])!=1){
		cout<<"1110";//02 01A 02 01C
	}else{
		cout<<"1111";//02 01B 02 01C
	}
	return 0;
}
