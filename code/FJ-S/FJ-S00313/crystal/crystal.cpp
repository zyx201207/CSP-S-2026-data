#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[100000];
	int cha;
	int x,cishu;
	int sum = 0;
	cin >> x >>cishu;
	for(int i = 0;i<x;i++){
		cin >> a[i];
	}
	if ((a[1]-a[0])!=(a[2]-a[1])){
		for (int i = 1;i<=x-1;i++){
		cha += a[i]-a[i-1];
		if(cishu>=cha){
			sum = i+1;
			}
		}
	}
	else{
 		for (int i = a[0];i<=x-1;i++){
			cha = a[1]-a[0];
			if (cishu>=(i+1)*i*cha/2){
				sum = i+1;
			}}}
	cout << sum;
	return 0;
	}

