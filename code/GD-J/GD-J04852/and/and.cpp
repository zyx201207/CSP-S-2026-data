#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		if(n==m){
			ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		int minn=0x3f;
		for(int i=1;i<=n;i++){
			minn=min(a[i],minn);
		}
		if(minn==a[1]){
			ans=a[2];
			for(int i=3;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
		else{
			ans=a[1];
			int z=0;
			for(int i=2;i<=n;i++){
				if(a[i]==minn) z++;
				if(z>1||z==0){
					ans=ans&a[i];
				}	
			}
			cout<<ans;
			return 0;
		}
		return 0;
	}
	if(m==2){
	sort(a+1,a+1+n);
	ans=a[n]&a[n-1];
	cout<<ans;
	return 0;	
	}
	if(n<=20){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>=n-m;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	} 
	return 0;
} 
