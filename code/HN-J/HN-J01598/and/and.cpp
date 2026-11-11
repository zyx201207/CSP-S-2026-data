#include <bits/stdc++.h>
using namespace std;

long long a[200005];
long long ans=INT_MAX;
int main(){
	long long max_=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_=max(max_,a[i]);
	}
	if(m==1){
		cout<<max_;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2 and m!=n){
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	
	
	return 0;
}
