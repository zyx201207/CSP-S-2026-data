#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int kc=ans;
		ans=a[i];
		for(int j=i+1;j<m+i;j++){
			ans=ans&a[j];
		}
		ans=max(ans,kc);
	}
	cout<<ans;
	return 0;
} 
