#include<bits/stdc++.h>
using namespace std;
int b[100001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	int a[100001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int v=0;v<n-1;v++){
		for(int u=0;u<n-1;u++){
			if(a[u]>a[u+1]){
				int x = a[u+1];
				a[u+1] = a[u];
				a[u] = x;
			}
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			b[j] = (a[i]-a[j]);
		}
		y = 1;
		for(int z=i-1;z>-1;z--){
			if(b[z]<=m){
				y += 1;
				m = m - b[z];
			}
		}
		if(y > x){
			x = y;
		}	
	}
	cout<<x+1;
	return 0;
} 
