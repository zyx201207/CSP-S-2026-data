#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],r,ans[300005],mp[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			ans[a[j]]++;
			j=mp[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

