#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int cnt=0,ans=0;
long long sum=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum+=(a[i]-a[i-1])*cnt;
		++cnt;
		while(cnt>0&&sum>m){
			sum-=a[i]-a[i-cnt];
			--cnt;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

