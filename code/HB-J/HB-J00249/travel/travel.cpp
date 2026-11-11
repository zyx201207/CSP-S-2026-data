#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool v[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1[0]==c3[0]&&c1[1]==c3[1]){
		printf("1");
		v[1]=1;
	}else{
		printf("0");
	}
	if(v[1]&&c2[0]==c4[0]&&c2[1]==c4[1]){
		printf("1");
		v[2]=1;
	}else{
		printf("0");
	}
	if(v[2]&&((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C'))){
		printf("1");
		v[3]=1;
	}else{
		printf("0");
	}
	if(v[3]&&((c2[2]+1)==c4[2]||(c2[2]-1)==c4[2])){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
