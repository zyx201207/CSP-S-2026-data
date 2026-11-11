#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
ll a[500005];
ll q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ull m;
	cin>>n>>m;
	bool isame=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		q[i]=q[i-1]+a[i];
		if(i>1&&a[i]!=a[i-1])isame=0;
	}
	if(isame){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==0){
		int mx=1;
		int sam=1;
		for(int i=2;i<=n;++i){
			if(a[i]!=a[i-1]){
				mx=max(mx,sam);
				sam=0;
			}
			++sam;
		}
		mx=max(mx,sam);
		cout<<mx;
		return 0;
	}
	int mx=1;
	if(n<=30000){
		for(int i=1;i<=n;++i){
			ll els=m;
			bool h=0;
			for(int j=n;j>=1;--j){
				els-=(a[i]-a[j]);
				if(els<0){
					h=1;
					mx=max(mx,i-j);
					break;
				}
			}
			if(h==0)mx=max(mx,i);
		}
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(1){
			if(l>=r){
				//cout<<l<<' ';
				mx=max(mx,i-l+1);
				break;
			}
			int mid=(l+r)/2;
			ull op=(i-mid+1)*a[i]-(q[i]-q[mid-1]);
			if(op>m){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	cout<<mx;
	return 0;
}
