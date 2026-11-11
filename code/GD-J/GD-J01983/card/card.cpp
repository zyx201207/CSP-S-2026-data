#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1010101],ans[1010101],f[1010101];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0) j=f[a[j]],ans[a[j]]++;
			else f[a[j]]=max(f[a[j]],j),ans[a[j]]++;
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
