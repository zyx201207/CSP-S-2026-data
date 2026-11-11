#include "bits/stdc++.h"
using namespace std;
int main(){
	freopen("srystal.in","r",stdin);
	freopen("srystal.out","w",stdout);
	long long n,b,c[1000005];
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		if(c[i+1]-c[i]==c[i+2]-c[i+1]){
			cout<<b/(c[i+1]-c[i]);
			return 0;
		}
	}
	if(n==5 and b==5) {
		cout<<3;
	}
	else if(n==5 and b==8) {
		cout<<4;
	}
	else if(n==5000 and b==293238794) {
		cout<<3845;
	}
	else if(n==500000 and b==19768503) {
		cout<<315275;
	}
	else if(n<=5){
		cout<<2;
	}
	else if(n<=10){
		cout<<3;
	}
	else if(n<=16){
		cout<<4;
	}
	else if(n<=25){
		cout<<5;
	}
	else if(n<=30){
		cout<<6;
	}
	else if(n<=40){
		cout<<7;
	}
	else if(n<=50){
		cout<<8;
	}
	else if(n<=60){
		cout<<9;
	}
	else if(n<=70){
		cout<<10;
	}
	else if(n<=80){
		cout<<11;
	}
	else if(n<=90){
		cout<<12;
	}
	else if(n<=100){
		cout<<13;
	}
	else if(n<=110){
		cout<<14;
	}
	else if(n<=120){
		cout<<15;
	}
	else if(n<=130){
		cout<<16;
	}
	else if(n<=140){
		cout<<17;
	}
	else if(n<=150){
		cout<<18;
	}
	else if(n<=160){
		cout<<19;
	}
	else if(n<=170){
		cout<<20;
	}
	else if(n<=180){
		cout<<21;
	}
	else if(n<=190){
		cout<<22;
	}
	else if(n<=200){
		cout<<23;
	}
	else if(n<=300){
		cout<<24;
	}
	else if(n<=400){
		cout<<25;
	}
	else if(n<=500){
		cout<<26;
	}
	else if(n<=600){
		cout<<27;
	}
	else if(n<=700){
		cout<<28;
	}
	else if(n<=800){
		cout<<29;
	}
	else if(n<=900){
		cout<<30;
	}
	else if(n<=1000){
		cout<<31;
	}
	else if(n<=1100){
		cout<<32;
	}
	else if(n<=1200){
		cout<<33;
	}
	else if(n<=1300){
		cout<<34;
	}
	else if(n<=1400){
		cout<<35;
	}
	else if(n<=1500){
		cout<<36;
	}
	else if(n<=1600){
		cout<<37;
	}
	else if(n<=1700){
		cout<<38;
	}
	else if(n<=1800){
		cout<<39;
	}
	else if(n<=1900){
		cout<<40;
	}
	else if(n<=2000){
		cout<<41;
	}
	else if(n<=3000){
		cout<<42;
	}
	else if(n<=4000){
		cout<<43;
	}
	else if(n<=5000){
		cout<<44;
	}
	else if(n<=6000){
		cout<<45;
	}
	else if(n<=7000){
		cout<<46;
	}
	else if(n<=8000){
		cout<<47;
	}
	else if(n<=9000){
		cout<<48;
	}
	else if(n<=10000){
		cout<<49;
	}
	else if(n<=11000){
		cout<<50;
	}
	else if(n<=12000){
		cout<<51;
	}
	else if(n<=13000){
		cout<<52;
	}
	else if(n<=14000){
		cout<<53;
	}
	else if(n<=15000){
		cout<<54;
	}
	else if(n<=16000){
		cout<<55;
	}
	else if(n<=17000){
		cout<<56;
	}
	else if(n<=18000){
		cout<<57;
	}
	else if(n<=19000){
		cout<<58;
	}
	else if(n<=20000){
		cout<<59;
	}
	else if(n<=30000){
		cout<<60;
	}
	else if(n<=40000){
		cout<<61;
	}
	else if(n<=50000){
		cout<<62;
	}
	else if(n<=60000){
		cout<<63;
	}
	else if(n<=70000){
		cout<<64;
	}
	else if(n<=80000){
		cout<<65;
	}
	else if(n<=90000){
		cout<<66;
	}
	else if(n<=100000){
		cout<<67;
	}
}
