#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,a[500005],p[500005],cf[500005],d[300005],cnt[300005];
vector<ll> v[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	p[1]=1;
	for(ll i=1;i<=n;i++){
		cf[i]=1;
	}
	
	 
	for(ll i=1;i<=n;i++){
		cf[v[a[i]][cnt[a[i]]]+1]-=i;
		cf[v[a[i]][v[a[i]].size()-1]]+=i;
		cnt[a[i]]++;
	} 
	for(ll i=2;i<=n;i++){
		p[i]=p[i-1]+cf[i];
		if(p[i]<0){
			p[i]=0;
		}
		d[a[i]]+=p[i];
	}
	d[a[1]]++;
	for(ll i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
} 
