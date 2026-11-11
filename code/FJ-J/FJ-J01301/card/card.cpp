#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005];
	cin>>n>>m;
	long long b[500005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	long long ans[50005]={};
	for(int i=1;i<=m;i++){
			if(b[i]==1&&i==m)
			ans[m]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
