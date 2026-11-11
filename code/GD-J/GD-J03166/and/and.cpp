#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,man;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==n){
		for(int i=1;i<=n;i++){
			man=man&a[i];
		}
		cout<<man<<"\n";
		return 0;
	}
	if(m==1){
		cout<<a[n]<<"\n";
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=a[i]&a[j];
				man=max(ans,man);
			}
		}
		cout<<man<<"\n";
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k){
					continue;
				}
				ans=a[i]&a[j]&a[k];
				man=max(ans,man);
				}
			}
		}
		cout<<man<<"\n";
		return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int zx=1;zx<=n;zx++){
				if(i==j||j==k||i==k||zx==i||zx==j||zx==k){
					continue;
				}
				ans=a[i]&a[j]&a[k]&a[zx];
				man=max(ans,man);
				}
			}
		}
		cout<<man<<"\n";
		return 0;
	}
}
	if(n==m+1){
		for(int i=1;i<=n;i++){
			ans=32767;
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=ans&a[j];
			}
			man=max(ans,man);
		}
		cout<<man<<"\n";
	}
	if(n==m+2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=32767;
				for(int l=1;l<=n;l++){
				if(l==j||l==i||i==j){
					continue;
				}
				ans=ans&a[l];
			}
			man=max(ans,man);
			}
		}
		cout<<man<<"\n";
	}
	else{
		cout<<a[n-m+1]<<"\n";
	}
	return 0;
}
