#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=-1,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=1;i<m;i++){
		ans&=a[n-i];
	}
	if(m==n){
		if(n<2){
			ans=1;
		}else{
			ans=0;
		}
	}
	if(m==1){
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
	}
	if(m==2){
		ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;
}
