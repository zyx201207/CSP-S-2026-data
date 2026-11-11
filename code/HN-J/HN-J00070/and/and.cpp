#include<bits/stdc++.h>
using namespace std;
int a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans;
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}
	if(m==1){
		ans=-1;
		for(int i=1;i<=n;i++){
			if(a[i]>ans) ans=a[i];
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
	return 0;
}
