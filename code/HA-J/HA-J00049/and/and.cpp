#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int ans=-1;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1) {
		for(int i=0;i<n;i++){
			if(a[i]>ans){
				ans=a[i];
			}
		}
	}
	if(m==2) {
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>ans){
					ans=a[i]&a[j];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
