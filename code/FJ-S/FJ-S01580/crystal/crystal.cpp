#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,inf=1e18;
int n,m;
int a[N];
int s[N],mx,mi=inf;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		
		int mid=(l+r+1)>>1;
		int cost=inf;
		for(int i=mid;i<=n;i++){
			cost=min(a[i]*mid-s[i]+s[i-mid],cost);
		}
		//cout<<mid<<' '<<cost<<"\n";
		if(cost>m)r=mid-1;
		else l=mid;
	}
	//cout<<r<<"\n";
	cout<<l;
	return 0;
}
