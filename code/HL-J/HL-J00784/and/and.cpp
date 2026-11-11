#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=n-1;i>0;i--){
		for(long long j=0;j<n;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	cout<<a[m-1];
	return 0;
}