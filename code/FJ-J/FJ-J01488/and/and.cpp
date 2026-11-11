#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int sum=a[0];
	for(int i=0;i<m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
