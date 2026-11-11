#include<bits/stdc++.h>
using namespace std;
int a[300000];
int h[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<n;i++){
			a[i+1]=a[i]&a[i+1];
		}
		cout<<a[n];
	}
	else if(m==1){
		a[0]=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]>a[0]) a[0]=a[i];
		}
		cout<<a[0];
	}
	else if(m==2){
		int u=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					h[u]=a[i]&a[j];
				}
			}
		}
		h[0]=h[1];
		for(int i=1;i<=n;i++){
			if(h[i]>h[0]) h[0]=h[i];
		}
		cout<<h[0];
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<n&&(j+1)!=i;j++){
				a[j+1]=a[j]&a[j+1];
				a[0]=a[j+1];
			}
		}
		cout<<a[0];
		return 0;
	}
}
