#include<iostream>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int num,daan=0,shu,zongshu=0;
	char a[200000];
	char zimu;
	cin>>num;
	for(int m=0;m<num;m++){
		cin>>shu;
		cin>>zimu;
		zongshu=zongshu+shu;
		for(long long int n=0;n<shu;n++){
			a[zongshu-shu+n]=zimu;
		}
	}
	for(long long int x=zongshu/2;x>0;x--){
		if(a[x-1]!=a[zongshu-x]){
			daan++;
		}
	}
	cout<<daan;
}
