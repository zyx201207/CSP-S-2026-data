#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],m;
ll maxx,minn;
ll check(ll mm){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=mm){
			sum+=mm-a[i];
		}else{
			break;
		} 
	}
	return sum;
}
int er(ll l,ll r){
	while(l<r){
		ll mid=(l+r+1)/2;
		ll k=check(mid);
		if(k<m){
			l=mid;
		}else{
			r=mid;
		}
		if(k==m){
			return r;
		}
		if(l+1==r)break;
	}
	return r; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
	sort(a+1,a+n+1);
	minn=a[1];maxx=a[n];
	ll pp=er(minn,maxx),cnt=0;
//	cout<<pp<<"\n";315275
	for(int i=n;i>=1;i--){
		if(a[i]>pp){
			continue;
		}else{
			m-=pp-a[i];
			if(m<0){
				break;
			}
			cnt++;
		}
		 
	}
	cout<<cnt;
	return 0;
}
