#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans,p,a[515414],f[514514],v[514514];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],f[a[i]]=i;
		if(a[i]>=a[i-1]) p++;
	}
	if(p==n){
		for(int i=1;i<=m;i++) cout<<f[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			v[a[j]]++;
			if(f[a[j]]>j) j=f[a[j]]+1;
			else j++;
		}
	} 
	for(int i=1;i<=m;i++) cout<<v[i]<<' ';
}
