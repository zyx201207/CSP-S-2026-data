#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005],f[200005],ans,l,r,b[36],c[36][200005];
ll dfs(ll k,ll x){
	ll sum=0;
	if(k>=m)return x;
	for(int i=1;i<=n;i++)if(!f[i])f[i]=1,sum=max(sum,dfs(k+1,(x&a[i]))),f[i]=0;
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m,b[0]=1;
	for(int i=1;i<=35;i++)b[i]=b[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=1,r=30;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(a[i]>=b[mid])l=mid;
			else r=mid-1;
		}c[l][++c[l][0]]=a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}for(int i=1;i<=n;i++)if(!f[i])f[i]=1,ans=max(ans,dfs(1,a[i])),f[i]=0;
	cout<<ans;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans,a[200005],b[35],c[35][200005],l=1,r=31;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m,b[0]=1;
	for(int i=1;i<=35;i++)b[i]=b[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=1,r=30;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(a[i]>=b[mid])l=mid;
			else r=mid-1;
		}c[l][++c[l][0]]=a[i];
	}
	for(int i=30;i>=1;i--){
		if(c[i][0]<m)
	}
	return 0;
}*/
