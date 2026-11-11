#include<bits/stdc++.h>
using namespace std;
int a[200001]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=a[n-m+1];
	for(int i=n-m+2;i<=n;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}
