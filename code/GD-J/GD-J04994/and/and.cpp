#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	long long maxx=-999;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	long long sum=a[0];
	for(int i=0;i<n;i++){
		sum=sum&a[i];
	}
	if(m==1){
		cout<<maxx;	
	}
	else if(m==n){
		cout<<sum;
	}	
	else if(m==2){
		sum=-999;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j!=i){
					sum=max(sum,a[i]&a[j]);
				}
			}
		}
		cout<<sum;
	}
	else if(m==n-1){
		
	}
	return 0;
}

