#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans[500005],l,d[500005],b[500005],f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
	}
	if(f==0){
		for(ll i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[a[i]]=ans[a[i-1]];
			}
			ans[a[i]]++;
		}
		for(ll i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(ll i=0;i<n;i++){
		for(ll j=1;j<=m;j++){
			d[j]=0;
		}
		for(ll j=1+i;j<=n;j++){
			if(d[a[j]]==0){
				d[a[j]]=1;
			}
			else{
				for(ll k=j-1;k>=1;k--){
					d[a[k]]=0;
					if(a[j]==a[k]){
						break;
					}
				}
				d[a[j]]=1;
			}
		}
		for(ll j=1;j<=m;j++){
			if(d[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
