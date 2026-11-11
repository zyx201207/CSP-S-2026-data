#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5*1e5+5;
ll n,m;
ll a[MAXN];
ll s[MAXN];
ll b[MAXN];
map<ll,ll> mp;
map<int,int> vis;
ll maxn(ll x,ll y){return x>y?x:y;}
ll absn(ll x){return x>0?x:-x;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int tmp=0;
	for(int i=n-1;i>=1;i--){
		tmp+=absn(a[i+1]-a[i]); 
		s[i]=s[i+1]+tmp;
	}
	for(int i=1;i<=n-1;i++){
		b[i]=s[i]-s[i+1];
	}
	int t=1,fans=1;
	int k;
	int ans=0;
	for(int i=1;i<=n;i++){
		k=i;
		fans=1;
		ans=0;
		if(vis[a[i]]){continue;}
		else{vis[a[i]]=1;}
		int l=1,r=i-1,mid;
		while(l<=r){
			mid=(l+r)/2;
			ans=s[mid]-s[k]-(k-mid)*b[k];
			if(ans>m){
				l=mid+1;
			}
			if(ans<=m){
				r=mid-1;
				fans=k-mid+mp[a[k]];
			}
		}
		t=maxn(t,fans);
	}
	cout<<t;
	return 0;
}



