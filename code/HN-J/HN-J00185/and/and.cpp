#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],x,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1)ans=max(ans,a[i]);
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++)ans=ans%a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<=n;k++){
					if(i!=j&&j!=k&&i!=k)ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<ans;
}
