#include<iostream>
#include<cmath>
using namespace std;

int a[100005];
int b[100005];

int main(){
	int n,cnt=0,Max=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int tmp=100005,tmpp;
		for(int j=1;j<=n-1;j++){
			if(tmp>a[j]){
				tmp=a[j];
				tmpp=j; 
			}
		}
		a[tmpp]++;
	} 
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		Max=max(a[i],Max);
	}
	int Max2=0;
	for(int i=1;i<=Max;i++){
		Max2=max(Max2,b[i]);
	}
	cout<<Max2;
	return 0;
} 
