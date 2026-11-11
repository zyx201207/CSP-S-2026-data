#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			long long ls=a[i]&a[j];
			ans=max(ans,ls);
		}
	}
	cout<<ans;
	return 0;
}
