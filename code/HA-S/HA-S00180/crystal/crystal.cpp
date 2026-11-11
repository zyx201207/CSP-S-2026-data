#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
	ll v,nm;
	ll c;
}t[510000];

ll n,m;
ll a[510000];
ll b[510000];
ll d[510000];
ll cnt;
ll ans;
ll aa,bb,cc;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		if (a[i]!=a[i-1]){
			t[++cnt].v=a[i];
			t[cnt].nm=1;
		}else t[cnt].nm++;
	}
	for (int i=1;i<=cnt;i++){
		b[i]=b[i-1]+t[i].nm;
	}
	for (int i=1;i<=cnt;i++){
		d[i]=d[i-1]+t[i].nm*t[i].v;
	}
	ll res,mm=m,ls;
	ans=t[1].nm;
	for (int i=2;i<=cnt;i++){
		mm=m;
		res=t[i].nm;
		ll l=1,r=i;
		while (l<r){
			ll mid=(l+r)/2;
			ls=t[i].v*(b[i-1]-b[mid-1])-d[i-1]+d[mid-1];
			if (ls>mm){
				l=mid+1;
			}else if (ls<mm){
				r=mid;
			}else{
				l=r=mid;
				break;
			}
		}
		res+=b[i-1]-b[l-1];
		mm-=t[i].v*(b[i-1]-b[l-1])-d[i-1]+d[l-1];
		if (mm&&l>1){
			res+=mm/(t[i].v-t[l-1].v);
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}


