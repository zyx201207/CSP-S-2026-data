#include<bits/stdc++.h>
using namespace std;
int n,m,a[300020],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
			for(int i=1;i<=n;i++){
				if(i==1){
				ans=a[2];
				for(int j=3;j<=n;j++){
					ans=ans&a[j];
				}
			}	
			else{
				ans=a[1];
				for(int j=2;j<=n;j++){
					if(j==i) continue;
					ans=ans&a[j];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else {
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1;i>n-m;i--){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
