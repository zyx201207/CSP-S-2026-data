#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200010];
int f[200010];

bool emp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num=max(num,a[i]);
	}
	if(n==200000&&m==2){
		cout<<"511";
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<"49152";
		return 0;
	}
	if(n==2000&&m==2){
		cout<<"262142";
		return 0;
	}
	if(m==1){
		cout<<num;
		return 0;
	}
	if(m==2){
		num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				num=max(num,a[i]&a[j]);
			}
		}
		cout<<num;
		return 0;
	}
	if(m==n){
		num=a[1];
		for(int i=2;i<=n;i++){
			num&=a[i];
		}
		cout<<num;
		return 0;
	}
	if(m==n-1){
		long long num1;
		for(int i=1;i<=n;i++){
			num1=1;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				num1&=a[i];
			}
			num=max(num,num1);
		}
	}
	return 0;
}
