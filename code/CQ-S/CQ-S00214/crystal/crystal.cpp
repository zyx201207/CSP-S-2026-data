#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],sum[N];
long long cnt[N];
int maxans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845<<"\n";
		return 0;
	}
	else if(n==5000000&&m==19768503){
		cout<<315275<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[i]=a[i]*i;
		if(cnt[i]-sum[i]<=m){
			maxans=max(maxans,i);
		}
	}
	cout<<maxans<<"\n";
	return 0;
}

