#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],t[300005],fa[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll n2=n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n>0){
		for(ll i=1;i<=m;i++){
			t[i]=0;
			fa[i]=0;
		}
		for(ll i=n2+1-n;i<=n2;i++){
			if(t[a[i]]==0){
				fa[a[i]]=i;
				t[a[i]]=1;
			}else{
				for(ll j=fa[a[i]]+1;j<i;j++){
					t[a[j]]=0;
					fa[a[j]]=0;
				}
				fa[a[i]]=i;
			}
		}
		for(ll i=1;i<=m;i++){
			ans[i]+=t[i];
		}
		n--;
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
