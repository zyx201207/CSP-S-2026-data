#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans & a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cnt=a[i];
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				cnt=ans & a[j];
				ans=max(cnt,ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			ans=a[i+1];
			for(int j=1;j<=n;j++){
				if(j!=i+1&&j!=i){
					ans=ans & a[j];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
