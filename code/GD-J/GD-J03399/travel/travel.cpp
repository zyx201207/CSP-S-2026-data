#include<bits/stdc++.h>
using namespace std;
char ac[3],bc[3],az[4],bz[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s",ac,az);
	scanf("%s %s",bc,bz);
	if(ac[0]==bc[0] && ac[1]==bc[1]){
		printf("1");
		if(az[0]==bz[0] && az[1]==bz[1]){
			printf("1");
			if(az[2]>='D' && bz[2]>='D'){
				printf("11");
			}
			else if(az[2]<'D' && bz[2]<'D'){
				printf("1");
				if(az[2]+1==bz[2] || az[2]-1==bz[2]) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	} 
	else printf("0000");
	
	return 0;
}
