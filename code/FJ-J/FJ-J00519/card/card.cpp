#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],b[500005],ans[500005],c[500005],d[500005];
vector<ll>v[500005];
bool is(ll x){
	if(x==1)return 1;
	for(auto i:v[x])if(c[i])return 0;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!b[a[i]])v[a[i]]=v[a[i+1]];
		if(!b[a[i]])v[a[i]].push_back(a[i+1]),b[a[i]]++;
	}for(int i=1;i<=300001;i++)b[i]=0;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(is(j))d[a[j]]=1;
		}for(int j=1;j<=m;j++)c[j]=b[j];
		for(int j=1;j<=m;j++){
			if(d[j])ans[j]++;
			d[j]=0;
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
