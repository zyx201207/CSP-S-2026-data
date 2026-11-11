#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int x=(a[i]&a[j]);
				if(maxx<x){
					maxx=(a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
	}
	else if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		}
		cout<<maxx;
	}
	else if(m==n){
		int maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
	}
	else if(m==n-1){
	    int s=a[2],maxx=0;
		for(int i=3;i<=n;i++){
			s=(s&a[i]);
		}
		for(int i=2;i<=n;i++){
			int sum=a[i];
			for(int j=2;j<=n;j++){
				if(j!=i){
					sum=(sum&a[j]);
				}
			}
			if(sum>maxx) maxx=sum;
		}
		cout<<maxx;
	}
	return 0;
}
