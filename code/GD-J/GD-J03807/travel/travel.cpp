#include<bits/stdc++.h>
using namespace std;

int main()
{
	preopon("travel.in",w,stdin);
	preopon("travel.out",r,stdout);
	string a[130] = {" ","01A","01B","01C"," ","01D","01F",
					" ","02A","02B","02C"," ","02D","02F",
					" ","03A","03B","03C"," ","03D","03F",
					" ","04A","04B","04C"," ","04D","04F",
					" ","05A","05B","05C"," ","05D","05F",
					" ","06A","06B","06C"," ","06D","06F",
					" ","07A","07B","07C"," ","07D","07F",
					" ","08A","08B","08C"," ","08D","08F",
					" ","09A","09B","09C"," ","09D","09F",
					" ","10A","10B","10C"," ","10D","10F",
					" ","11A","11B","11C"," ","11D","11F",
					" ","12A","12B","12C"," ","12D","12F",
					" ","13A","13B","13C"," ","13D","13F",
					" ","14A","14B","14C"," ","14D","14F",
					" ","15A","15B","15C"," ","15D","15F",
					" ","16A","16B","16C"," ","16D","16F",
					" ","17A","17B","17C"," ","17D","17F",
					" ","18A","18B","18C"," ","18D","18F"};
	string b,c,d,e;
	int ai,zi;
	int t,f; 
	cin >>b>>c>>e>>d;
	if(b == e){
		cout << 1;
		for (int i = 0;i <= 130 ; i++){
			if(c == a[i]){
				ai == i;
			}
			if(d == a[i]){
				zi == i;
			}
		}
		if(ai/7 == zi/7){
			cout << 1;
			for(int i = 1;i <= 6;i++){
				ai++;
				if (ai == zi){
					t = 1;
					break;  
				}
				else{
					t = 0;
				}
			}
			for(int i = 1;i <= 6;i++){
				ai--;
				if (ai == zi){
					f = 1;
					break;  
				}
				else{
					f = 0;
				}
			}
			if (t == 1 || f == 1){
				cout << 1;
				if(ai + 1 == zi || ai - 1 == zi){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
			cout << 0 << 0;
			}
		}
		else{
			cout << 0 << 0 << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0; 
	} 
	
	return 0; 
} 
 
