#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		printf("0000\n");
	} else {
		ll a3=a2[0]*10+a2[1];
		ll b3=b2[0]*10+b2[1];
		char a4=a2[2];
		char b4=b2[2];
		if(a4=='D') a4++;
		if(b4=='D') b4++;
		if(a3!=b3){
			printf("1000\n");
		} else if((a4>'D'&&b4<'D')||(a4<'D'&&b4>'D')){
			printf("1100\n");
		} else if(abs(a4-b4)!=1){
			printf("1110\n");
		} else {
			printf("1111\n");
		}
	}
	return 0;
}
/*

*/