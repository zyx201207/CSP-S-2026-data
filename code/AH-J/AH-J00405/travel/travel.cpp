#include<bits/stdc++.h> 
using namespace std;
int cx,cy;
char sx[5],sy[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>cx>>sx[1]>>sx[2]>>sx[3]>>cy>>sy[1]>>sy[2]>>sy[3];
	if(cx!=cy){
		printf("0000");
		return 0;
	}
	else printf("1");
	if(sx[1]!=sy[1]||sx[2]!=sy[2]){
		printf("000");
		return 0;
	}
	else printf("1");
	if((sx[3]<='C'&&sy[3]>'C')||(sx[3]>'C'&&sy[3]<='C')){
		printf("00");
		return 0;
	}
	else printf("1");
	if(abs(sx[3]-sy[3])!=1){
		printf("0");
		return 0;
	}
	else printf("1");
	return 0;
}
//这应该是蒟蒻的最后一场考试了嘻嘻嘻，蒟蒻学得比较晚、比较少，所以期待这次可以发挥好一点嘿嘿
// 佬 OTZ

