#include<bits/stdc++.h>
using namespace std;
int a[200005],mx=-1;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){cout<<mx;return 0;}
	if(m==2){
		mx=-1;
		for(int i=1;i<n;i++) {
			for(int j=i+1;j<=n;j++) {
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;return 0;
	}
	if(m==3){
		mx=-1;
		for(int i=1;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				for(int k=j+1;k<=n;k++){
					mx=max(mx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
