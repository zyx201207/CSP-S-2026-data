#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string a;
	char p='p';
	a+=p;
	long long num=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		long long j;
		char y;
		cin>>x>>y;
		long long x2=x/4;
		for(j=0;j<x2;j++){
			a+=y;
		}
		for(j=x2;j<x2*2;j++){
			a+=y;
		}
		for(j=x2*2;j<x2*3;j++){
			a+=y;
		}
		for(j=x2*3;j<x;j++){
			a+=y;
		}
		num+=j;
	}
	long long sum=0;
	long long num2=num;
	if(num%2!=0){
		num2--;
		for(long long i=1;i<=num2/2;i++){
			if(a[i]!=a[num-i]){
				sum++;
			}
		}
	}else{
		num2-=2;
		for(long long i=1;i<=num2/2;i++){
			if(a[i]!=a[num-i]){
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
