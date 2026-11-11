#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],ans,as;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-m;i++){
		as=a[i];
		for(int j=i+1;j<=n;j++){
			as=as&a[j];
		}
		ans=max(ans,as);
	}
	cout<<ans;
	return 0;
}
