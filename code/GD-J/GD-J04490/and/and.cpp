#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,d;
	cin>>n>>d;
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<d;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int sum=a[n-1];
	for(int i=n-1;i>n-1-d;i--){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
} 
