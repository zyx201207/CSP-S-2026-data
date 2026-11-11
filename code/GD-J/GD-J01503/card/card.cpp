#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+c[i];
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

