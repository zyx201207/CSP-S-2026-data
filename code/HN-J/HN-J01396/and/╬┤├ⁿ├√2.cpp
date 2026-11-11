#include<iostream>
using namespace std;
int a[10000000];
int b[10000000];
int main () {
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	long long c=10;
	for(int i=0;i<n;i++){
		while(a[i]>1){
			a[i]=a[i]/2;
			b[i]=a[i]%2*c;
			c=c*10;
		}
	}
	int max=-100000;
	for(int i=0;i<n;i++){
		if(b[i]+b[i+1]>max){
			max=b[i]+b[i+1];
		}
	}
	int p=0,f=1;
	while(max>1){
		p=p+max%10*2*f;
		max=max/10;
		f=f*10;
	}
	cout<<p;
	return 0;
}
