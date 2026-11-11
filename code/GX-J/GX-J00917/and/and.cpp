#include <bits/stdc++.h>
using namespace std;
int smp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.out","w",stdout);
	freopen("and1.in","r",stdin);
	int n,arr[200001]={},m,arr1[200001]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,smp);
	for(int i=0;i<m;i++){
		arr1[i]=arr[i];
	}
	sort(arr,arr+n);
	cout<<arr1[1] and arr1[0];
	return 0;
}
