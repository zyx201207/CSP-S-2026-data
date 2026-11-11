#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		ll vis[300005]={},xx[500005],st[500005],top=0;
		for(ll j=i;j<=n;j++){
			if(vis[a[j]]==0){
				st[++top]=a[j];
				xx[a[j]]=top;
				vis[a[j]]=1;
			}else{
				for(ll k=xx[a[j]]+1;k<=top;k++){
					vis[st[k]]=0;
				}
				top-=(top-xx[a[j]]+2);
			}
		}
		for(ll j=1;j<=top;j++){
			ans[st[i]]++;
		}
		
	}
	for(ll i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

