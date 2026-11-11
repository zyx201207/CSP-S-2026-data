#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],ans[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
		if(i==b[a[i]]&&i<n){
			ans[a[i+1]]+=ans[a[i]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
