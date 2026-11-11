#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long arr[110000000];
int aaa(int n){
	int m[10000]={},i=0;
	while(n>=0){
		m[i++]=n%2;
	n/=2;
	}
	int ans=0;
	/*for(int j=i-1;j>=0;j--){
		ans=ans*10+m[j];
	}*/
	for(int j=0;j<n;j++){
		ans=ans*10+m[j];
	}
	return ans;
}
int main(){
	freopen("and.in","r",and.in);
	freopen("and.out","w",and.out);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	sort(arr,arr+m);
	int ans_=0,cut=1;
	for(int i=0;i<n;i++){
		int t1=aaa(arr[m-i-1]);
		while(cut!=0||t1!=0){
			ans_=ans_*10+cut%10&&t1%10;
		}
	}
	int an=0;
	while(ans1>0){
		an=an*10+ams_%10;
		ans1/=10;
	}
	cout<<an;
	return 0;
}
