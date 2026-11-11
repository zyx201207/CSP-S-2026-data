#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >>m;
	int ls[100000]={};
	for(int i=0;i<n;i++)cin >> ls[i];
	sort(ls,ls+n);
	int sum=ls[n-1];
	for(int i=n-m+1;i<n;i++){
		sum=sum&ls[i];
	}
	cout << sum;
} 
