#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005],ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=max(f[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(f[a[j]]>j){
				j=f[a[j]];
				continue;
			}else{
				ans[a[j]]++;
				j++;
			}
			
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
