#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m||n==m+1){
		for(int i=1;i<=n;i++){
			if(i==1) ans=a[i];
			ans=ans&a[i];
		}
		if(n==m+1){
			for(int i=1;i<=n;i++){
				x=max(x,ans|a[i]);
			}
			ans=x;
		}
		cout<<ans;
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
