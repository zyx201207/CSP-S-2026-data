#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		printf("0000");
		return 0;
	}
	if((sr[0]!=sx[0])||(sr[1]!=sx[1])){
		printf("1000");
		return 0;
	}
	if(sr[2]<='C'){
		if(sx[2]>'C'){
			printf("1100");
			return 0;
		}
	}
	else{
		if(sx[2]<='C'){
			printf("1100");
			return 0;
		}
	}
	if((sr[2]-sx[2]==1)||(sx[2]-sr[2]==1))
		printf("1111");
	else
		printf("1110");
	return 0;
}
