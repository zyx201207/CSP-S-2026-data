#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=0;i--){
		int x=a[i];
		for(int j=1;j<m;j++){
			x=x&a[i-j];
		}
			ans=max(x,ans);		
	}
	cout<<ans;
	return 0;
}
