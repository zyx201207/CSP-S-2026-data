#include <bits/stdc++.h>
using namespace std;
long long m,n,a[20005],ans=-2e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++) s&=a[i];
		cout<<s;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				long long x=a[i]&a[j];
				ans=max(ans,x);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long x;
		for(int i=1;i<=n;i++){
			if(i==1) x=a[2];
			else x=a[1];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else x&=a[j];
			}
			ans=max(ans,x);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
