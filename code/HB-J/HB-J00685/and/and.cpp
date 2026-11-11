#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=m;i++){
			n = n&a[i];
		}
		cout<<n;
	}
	if(m==1){
		int x = -1;
		for(int i=1;i<=m;i++){
			x = max(x,a[i]);
		}
		cout<<x;
	}
	if(m==n-1){
		int y = -1,cnt = 0;
			for(int i=1;i<=m;i++){
					for(int j=1;j<=m;j++){
						if(j==i) continue;
						cnt = cnt&a[j];
					}
					y = max(y,cnt);
			}
		cout<<y;
	}
	if(m==2){
		int x = -1;
		for(int i=1;i<n;i++){
			for(int j = i+1;j<=n;j++){
				
				x = max(x,a[i]&a[j]);
			}
		}
		cout<<x;
	}
	
}
