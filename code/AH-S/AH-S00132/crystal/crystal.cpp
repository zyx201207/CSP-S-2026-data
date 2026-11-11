#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
bool check(int now){
	long long ned=0;
	int i=1;
	for(i=1;i<now;i++){
		ned+=a[now]-a[i];
	}
	if(ned<=m)return 1;
	for(int i=now+1;i<=n;i++){
        ned+=(a[i]-a[i-1])*1ll*now;
        ned-=a[i]-a[i-now];
        if(ned<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n,ans=1;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
    return 0;
}
