#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]&a[i+1]);
	}
	cout<<ans;
	return 0;
}
