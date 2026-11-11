#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans=max(ans,a[i] & a[j]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
