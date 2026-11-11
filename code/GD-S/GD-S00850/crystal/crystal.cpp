#include<bits/stdc++.h>

using namespace std;
const int maxn=5e5+10;
long long n,m;
long long a[maxn];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long nfm=0;
	long long cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		nfm+=1LL*(a[i]-a[i-1])*cnt;
		while(cnt!=0 && nfm>m){
			nfm-=(a[i]-a[i-cnt]);
			cnt--;
		}
		cnt++;
		ans=max(cnt,ans);
	}
	cout<<ans<<'\n';
	return 0;
}
