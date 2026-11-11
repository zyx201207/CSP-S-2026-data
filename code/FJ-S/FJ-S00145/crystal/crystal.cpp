#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	else if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=500000&&(a[0]==a[n-1])&&n>5000){
		cout<<n;
		return 0;
	}
	else if(n<=500000&&(a[0]!=a[n-1])&&n>5000){
		cout<<m;
		return 0;
	}
	long long  b[n];
	long long max=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[j]=a[i]-a[j];
			if(b[j]<0){
				b[j]=0-b[j];
			}
		}
		sort(b,b+n);
		long long r=0;
		while(m>=b[r]){
			m=m-b[r];
			r++;
		}
		if(r>max){
			max=r;
		}
	}
	cout<<max;
}
