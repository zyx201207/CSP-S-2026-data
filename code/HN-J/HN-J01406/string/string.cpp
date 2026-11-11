#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w".stdout);
	int n;
	cin>>n;
	int a[200090];
	char c[200090];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	char x[200090];
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			x[sum]=c[i];
			sum++;
		}
	}
	int z=0;
	char y[200090]={};
	for(int i=sum;i>=0;i--){
		y[z]=x[i];
		z++;
	}
	int cnt=0;
	for(int i=sum;i>=0;i--){
		if(y[i]!=x[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
