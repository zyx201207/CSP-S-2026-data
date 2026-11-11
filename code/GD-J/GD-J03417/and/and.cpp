#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,x;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1)cout<<0;
	if(m==n){
		x=a[1];
		for(int i=2;i<=n;i++){
			x=(x&a[i]);
		}cout<<x;
	}
	if(m==2){
		x=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				x=max((a[i]&a[j]),x);
			}
		}cout<<x;
	}
	if(m==n-1){
		x=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					x=max((a[i]&a[j]),x);
				}
			}
		}cout<<x;
	}
	
	
	
	
	
	
	
	return 0;
}
