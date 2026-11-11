#include<bits/stdc++.h>
using namespace std;
int n,m,mx=-1e9,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,(a[i]&a[j]));
		}
	}
	cout<<mx;
	return 0;
}
