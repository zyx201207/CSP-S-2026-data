#include<bits/stdc++.h>
using namespace std;
int m,n,a[20001],num2;
int add(int t,int cishu){
	int num1=0;
	if(cishu==m){
		for(int i=t+1;i<n;i++){
			num2=a[t]&a[i];
			if(num2>num1){
				num1=num2;
			}
		}
		return num1;
	}else{
		for(int i=t;i<n-t;i++){
			num2=a[i]&add(i,cishu+1);
			if(num2>num1){
				num1=num2;
			}
		}
		return num1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	int num1=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		num2=add(i,1);
		if(num2>num1){
			num1=num2;
		}
	}
	cout<<num1;
	fclose(stdin);
	fclose(stdout);
}
