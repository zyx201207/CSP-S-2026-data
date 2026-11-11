#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;

int n;ll m;

ll a[MAXN];

ll L[MAXN],R[MAXN];
ll s[MAXN];
ll b[MAXN];
int t;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(i==1||a[i]!=a[i-1]){
			R[t]=i-1;
			L[++t]=i;
		}
	}
	R[t]=n;
	ll ans=0;
	for(int i=1;i<=t;++i){
		b[i]=a[L[i]];
		s[i]=s[i-1]+b[i]*(R[i]-L[i]+1);
	}
	for(int i=1;i<=t;++i){
		if(i==1){
			ans=max(ans,R[i]-L[i]+1);
			continue;
		}
		if((R[i-1]-L[i-1]+1)*(b[i]-b[i-1])>m){
			ans=max(ans,R[i]-L[i]+1+m/(b[i]-b[i-1]));
			continue;
		}
//		cout<<i<<'\n';
		int l=1,r=i-1;
		while(r-l>1){
			int mid=l+(r-l>>1);
			if((R[i-1]-L[mid]+1)*b[i]-(s[i-1]-s[mid-1])>m) l=mid+1;
			else r=mid;
		}
		if((R[i-1]-L[l]+1)*b[i]-(s[i-1]-s[l-1])<=m) r=l;
		ll res=R[i]-L[i]+1;
		ll mres=m;
		res+=R[i-1]-L[r]+1,mres-=(R[i-1]-L[r]+1)*b[i]-(s[i-1]-s[r-1]);
		if(r>1){
			res+=mres/(b[i]-b[r-1]);
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
