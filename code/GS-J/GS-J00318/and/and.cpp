#include<iostream>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int xuan,num,daan;
	int a[200000];
	cin>>num;
	cin>>xuan;
	for(int m=0;m<num;m++){
		cin>>a[m];
	}
	if(xuan==1){
		daan=a[0];
		for(int n=1;n<num;n++){
			if(a[n]>daan){
				daan=a[n];
			}
		}
		cout<<daan;
	}
	else if(xuan=2){
		daan=(a[0]&a[1]);
		for(int x=0;x<num-1;x++){
			for(int y=1+x;y<num;y++){
				if((a[x]&a[y])>daan){
					daan=(a[x]&a[y]);
				}
			}
		}
		cout<<daan;
	}
	return 0;
}
