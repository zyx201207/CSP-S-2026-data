//GZ-S00047 毕节七星关东辰实验学校 杜启民 
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define heap priority_queue
using namespace std;

const int N=5e5+10;

int n;
ll m,a[N];
ll sum[N];

void solve(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){sum[i]=sum[i-1]+a[i];}
	
	ll k=0,p=1,ans=0;
	for(int i=1;i<=n;i++){
		k+=(1LL*(a[i]-a[i-1])*(i-p));
		while(p<=i&&k>m){k-=(a[i]-a[p]);p++;}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	
	return;
}

int main(){
	
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T=1;
	//cin>>T;
	while(T--){solve();}
	
	return 0;
}
