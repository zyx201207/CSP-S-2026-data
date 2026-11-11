#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",std);
	freopen("and.out","w",std);
	int a,b,c=0;
	cin>>a>>b;
	int arr[200005];
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	sort(arr,arr+a);
	c=arr[a-1];
	for(int i=a-1;i>a-b-1;i--){
		c=c&arr[i];
	}
	cout<<c;
	return 0;
}
