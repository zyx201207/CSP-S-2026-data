#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=0;
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	if(m==1){
		cout<<a[1];
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
	}
	if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;j<=n;j++){
					ans=max(a[i]&a[j]&a[k],ans);
				}
			}
		}
	}
	if(m==4){
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;j<n;j++){
					for(int l=k+1;l<=n;l++){
						ans=max(a[i]&a[j]&a[k]&a[l],ans);
					}
				}
			}
		}
	}
	cout<<ans;
return 0;
}
