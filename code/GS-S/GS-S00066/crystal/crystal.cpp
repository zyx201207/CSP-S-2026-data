#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=500005;
ll m,sj[MAXN],c;
ll mid=0;
int n;
int check(ll tar){
	ll k=0;
	c=0;
	for(ll i=n-1;i>=0;i--){
		if(sj[i]<=tar){
			ll need=tar-sj[i];
			k+=need;
			if(k>m)return c;
			else c+=1;
		}
	}
	return c;
}
bool check2(ll tar){
	ll k=0;
	c=0;
	for(ll i=n-1;i>=0;i--){
		if(sj[i]<=tar){
			ll need=tar-sj[i];
			k+=need;
			if(k>m)return 0;
			else c+=1;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll sum=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>sj[i];
	sort(sj,sj+n);
	for(int i=0;i<n;i++)
		sum+=sj[n-1]-sj[i];
	if(m>sum){
		cout<<sum;return 0;
	}
	ll maxn=0;
	ll l=sj[0],r=sj[n-1];
	check(r);maxn=max(maxn,c);
	check(l);maxn=max(maxn,c);
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)<maxn)
			l=mid;
		else r=mid-1;
		maxn=max(maxn,c);
	}
	l=sj[0],r=sj[n-1];
	while(l<r){
		int mid=(l+r+1)/2;
		if(check2(mid)){
			l=mid;
		}
		else r=mid-1;
		maxn=max(maxn,c);
	}
	cout<<maxn;
	return 0;
} 
