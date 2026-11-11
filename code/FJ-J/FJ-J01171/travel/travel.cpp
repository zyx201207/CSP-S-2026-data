#include <bits/stdc++.h>
using namespace std;
int cx1,cx2,ans=0;
string zw1,zw2;
bool pdtc(string zw1,string zw2){
	if (zw1[2]=='A' || zw1[2]=='B' ||zw1[2]=='C' &&zw2[2]=='A' ||zw2[2]=='B' ||zw2[2]=='C'){
		return 1;
	}else if(zw1[2]=='F' || zw1[2]=='E' &&zw2[2]=='E' ||zw2[2]=='F'){
		return 1;
	}
	return 0;
}
bool pdxl(string zw1,string zw2){
	if(zw1[2]=='A'&&zw2[2]=='B'){
		return 1;
	}else if(zw1[2]=='B'&&zw2[2]=='C'){
		return 1;
	}else if(zw1[2]=='E'&&zw2[2]=='F'){
		return 1;
	}else if(zw1[2]=='B'&&zw2[2]=='A'){
		return 1;
	}else if(zw1[2]=='C'&&zw2[2]=='B'){
		return 1;
	}else if(zw1[2]=='F'&&zw2[2]=='E'){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if (cx1==cx2){
		if (zw1[1]==zw2[1] && zw1[0]==zw2[0]){
			if(pdtc(zw1,zw2)){
				if(pdxl(zw1,zw2)){
					printf("%d","1111");
					return 0;
				}
				printf("%d","1110");
				return 0;
			}
			printf("%d","1100");
			return 0;
		}
		printf("%d","1000");
		return 0;
	}else{
		printf("%d","0000");
		return 0;
	}
} 
