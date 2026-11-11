#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long mx=-1;
	for(int i=1;i<=n-m;i++){
		long long ans=a[i];
		for(int j=i+1;j<=m;j++){
			ans=ans&a[j];
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
