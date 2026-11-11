#include<bits/stdc++.h>
using namespace std;
//crystal
long long n,m;
long long a[500500];
long long cf[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	int ans=0;
	long long now=0;
	int l=1,r=1;
	while(l<=r && r<n){
		while(now+1LL*(r-l+1)*cf[r+1]<=m && r<n){
			now=now+1LL*(r-l+1)*cf[r+1];
			r++;
		}
		ans=max(ans,r-l+1);
//		cout<<l<<" "<<r<<" : "<<now<<endl;
		now=now-a[r]+a[l];
		l++;
	}
	cout<<ans;
	return 0;
}

