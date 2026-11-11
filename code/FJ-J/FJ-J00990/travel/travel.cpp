#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string st1,st2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>st1>>n2>>st2;
	if(n1!=n2){
		printf("0000");
	}else if(st1[0]!=st2[0] || st1[1]!=st2[1]){
		printf("1000");
	}else if(!((st1[2]>='D' && st2[2]>='D')||(st1[2]<='C' && st2[2]<='C'))){
		printf("1100");
	}else if(!((st1[2]+1==st2[2]) || (st1[2]-1==st2[2]))){
		printf("1110");
	}else{
		printf("1111");
	}
	printf("\n");
	return 0;
}

