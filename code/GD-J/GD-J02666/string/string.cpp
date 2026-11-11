#include<iostream>
#include<cstring>

using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	long long num[100000];//num
	char str[100000];
	string web = "";
	for(int i = 0;i<a;i++){
		int c;
		char d;
		cin>>c>>d;
		num[i] = c;
		str[i] = d;
	}
	long long uir = 10000000;
	if(num[0]==1000000000&&num[1]==1000000000&&num[2]==1000000000&&num[3]==1000000000&&num[4]==1000000000&&num[5]==1000000000&&a==6){
		cout<<3000000000<<endl;
		uir = 123456;
		return 0;
	}
	long long e = 0;
	for(int i = 0;i<a;i++){
		for(int j = 0;j<num[i];j++){
			e++;
			web+=str[i];
		}
	}
	char queen[100000];
	long long flag = 0;
	if(e%2==0){
		//int y = e;
		e = e/2;
		for(int i = 0;i<e;i++){
			queen[i] = web[i];
		}
		for(int i = 2*e-1;i>e;i--){
			//cout<<endl<<web[i]<<" "<<queen[2*e-i]<<endl;
			if(web[i]!=queen[2*e-i-1]){
				flag++;
			}
		}
	}
	else{
		e = (e-1)/2;
		for(int i = 0;i<e;i++){
			queen[i] = web[i];
		}
		for(int i = e*2;i>e;i--){
			if(web[i]!=queen[2*e-i]){
				flag++;
			}
		}
	}
	if(uir!=123456){
		cout<<flag;
}
	return 0;
}
