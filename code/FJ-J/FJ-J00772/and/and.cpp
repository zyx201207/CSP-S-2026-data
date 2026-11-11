#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i]; 
	} 
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	if(m==2){
		long long x=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(a[i]>=x&&a[j]>=x) x=a[i]&a[j];
			} 
		}
		cout<<x;
	}
	if(m==3){
		long long x=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				for(int l=j+1; l<n; l++){
					if(a[i]>=x&&a[j]>=x&&a[l]>=x) x=a[i]&a[j]&a[l];
				}
			} 
		}
		cout<<x;
	}
	return 0;
}

