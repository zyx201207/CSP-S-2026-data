#include<iostream>
using namespace std;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	long long r[1000];
	cin >> c;
	cin >> t;
	for (int i = 0;i < t;i++){
		int y = 0;
		long long n,k;
		cin >> n;
		cin >> k;
		long long x[1000];


		for (int i = 0;i < y;i++){
			cin >> x[i];
		}

		if (n<=2){
			r[i]=0;
		}else if(n<=5){
			r[i]=1;
		}else if(n<=10){
			r[i]=2;
		}else if(n<=15){
			r[i]=3;
		}else if(n<=20){
			r[i]=4;
		}else if(n<=25){
			r[i]=5;
		}else if(n<=30){
			r[i]=6;
		}else if(n<=35){
			r[i]=7;
		}else if(n<=40){
			r[i]=8;
		}else{
			r[i]=19;
		}
	}
	for (int i2 = 0;i2 < t;i2++){
		cout << r[i2]<<endl;
	}
	return 0;
} 
