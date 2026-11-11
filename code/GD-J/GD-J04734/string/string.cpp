#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+14;
ll g[N],n,len,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i]>>c[i];
		len+=g[i];
	}
	for(ll l=1,r=n;l<r;){
		if(c[l]!=c[r])ans+=min(g[l],g[r]);
		if(g[l]>g[r])g[l]-=g[r],r--;
		else if(g[l]<g[r])g[r]-=g[l],l++;
		else r--,l++;
	}
	cout<<ans;
	return 0;
}
