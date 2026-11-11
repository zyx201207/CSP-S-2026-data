#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,x,a[500010],m,vis[5010],f[500010],mx,k,d[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=i+1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				f[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			if(f[l]==l+1) d[a[l]]++,l++;
			else l=f[l];
		}
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
}
