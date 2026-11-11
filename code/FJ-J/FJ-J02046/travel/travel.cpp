#include<iostream>
#include<cmath>
using namespace std;
int ca,sa,cb,sb,a;
string saa,sba;
int main(){
	cin>>ca>>sa>>saa>>cb>>sb>>sba;
	for(int i=1;i<=1;i++){
		if(ca==cb){
			cout<<1;
		}else{
			cout<<0<<0<<0<<0;
			break;
		}
		if(sa==sb){
			cout<<1;
		}else{
			cout<<0<<0<<0;
			break;
		}
		if(saa<="C" && sba<="C"){
			cout<<1;
			a=1; 
		}else if(saa>"C" && sba>"C"){
			cout<<1<<1;
			break;
		}else{
			cout<<0<<0;
			break;
		}
		if (a==1){
			if(saa=="A" && sba=="B"){
				cout<<1;
			}else if(saa=="B" && sba=="A"){
				cout<<1;
			}else if(saa=="B" && sba=="C"){
				cout<<1;
			}else if(saa=="C" && sba=="B"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
} 

