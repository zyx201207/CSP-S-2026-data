#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==1){
		cout<<"1";
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int l=i;l<n;l++){
			if(a[l]<a[i]){
				int t=a[l];
				a[l]=a[i];
				a[i]=t;
			}
		}
	}
	cout<<n;
	return 0;
} 
