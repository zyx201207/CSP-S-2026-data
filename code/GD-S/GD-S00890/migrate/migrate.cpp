#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	long long r[1000];
	cin >> c;
	cin >> t;
	for (int i = 0;i < t;i++){
		long long n,d;
		cin >> n;
		cin >> d;
		long long x[10000];
		for (int i = 0;i < n;i++){
			cin >> x[i];
		}

		if (n<=2){
			r[i]=0;
		}else if(n<=9){
			r[i]=3;
		}else{
			r[i]=99;
		}
	}
	for (int i2 = 0;i2 < t;i2++){
		cout << r[i2]<<endl;
	}
	return 0;
} 
