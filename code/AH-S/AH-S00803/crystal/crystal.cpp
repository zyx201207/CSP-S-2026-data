#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("crystal.in","r","stdin")
//freopen("crystal.out","w","stdout")
	int m,n,a[500000];
	int i;
	cin>>n>>m;
	for(i=0;i<=n-1;i++){
		cin>>a[i];
	}
	int arr[500000],j,b;
	for(j=n;j>=0;j--){
		if(arr[j]<arr[j-1]){
			b=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=b;
		}
	}
	int sum=0;
	for(i=0;i<=n;i++){
		for(int j=0;j<=n-1;j++){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
