#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int main(){
	freopen("and.in","R",stdin);
	freopen("and.out","W",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		
	}
	if(n%2==0){
		t=0+2;
	}
	if(n%2==1){
		t=1+2;
	}
	for(int i=1;i<2;i++){
		sort(arr+1,arr+n+1);
		cout<<arr[t];
	}
	return 0;
}
