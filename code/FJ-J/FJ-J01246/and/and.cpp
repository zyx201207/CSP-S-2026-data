#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=-1e9;
		for(int i=1;i<=n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx;
	}else if(n<=2000&&m==2){
		int mx=-1e9;
		for(int i=1;i<n;i++){
			int o=a[i];
			for(int j=i+1;j<=n;j++){
				o&=a[j];
				mx=max(mx,o);
			}
		}
		cout<<mx;
	}else if(n==m){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
	} 
	return 0;
} 
