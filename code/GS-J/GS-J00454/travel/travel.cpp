#include<bits/stdc++.h>
using namespace std;
string a,az,b,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>az>>b>>bz;
	if(a!=b){
		printf("0000");
		return 0;
	}
	if(az[0]!=bz[0] || az[1]!=bz[1]){
		printf("1000");
		return 0;
	}
	if(az[2]=='A' || az[2]=='B' || az[2]=='C'){
		if(bz[2]!='A' && bz[2]!='B' && bz[2]!='C'){
			printf("1100");
			return 0;
		}
		else{
			if((az[2]=='A' && bz[2]=='B') || az[2]=='B' || (az[2]=='C' && bz[2]=='B')){
				printf("1111");
				return 0;
			}
			printf("1110");
			return 0;
		}
	}
	else{
		if(bz[2]!='D' && bz[2]!='F'){
			printf("1100");
			return 0;
		}
		else{
			printf("1111");
			return 0;
		}
	}
	return 0;
}
