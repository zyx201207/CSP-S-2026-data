#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans<<endl;
	}else if(m==1){
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
	}else if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	return 0;
}