#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	int ans;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m;j++){
			ans=a[i]&a[j];
			maxn=max(maxn,ans);
		}
	}
	cout<<maxn;
	return 0;
}
