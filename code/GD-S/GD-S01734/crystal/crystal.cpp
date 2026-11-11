#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,i;
ll maxa=-1e18,mina=1e18;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		mina=min(mina,a[i]);
	}
	ll l=mina,r=maxa,mid,num;
	while(l<r){
		mid=(l+r+1)/2;
		num=0;
		for(i=1;i<=n;i++){
			if(a[i]<mid) num+=mid-a[i];
		}
		if(num<=m) l=mid;
		else r=mid-1;
	}
	ll cnt=0;
	for(i=1;i<=n;i++){
		if(a[i]<=l) cnt++;
	}
	cout<<cnt;
	return 0;
}
