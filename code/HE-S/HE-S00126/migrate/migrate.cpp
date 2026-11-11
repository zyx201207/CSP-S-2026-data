#include <bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
const long long M=1e3+10;
long long c,T,n,d,a[N];
long long mins,bj,last;
void dfs(long long now,long long fin,long long sum){
	if(sum>mins) return;
	if(now==fin){
		if(sum==mins){
			bj+=1;
		}else if(sum<mins){
			bj=0;
			mins=sum;
		}
		return;
	}
	for(int i=now+1;a[i]-a[now]<=d&&i<=fin;i=i+1){
		dfs(i,fin,sum+1);
	}
}
void solve(){
	long long ans=0,bj1=0;
	cin>>n>>d;
	for(int i=1;i<=n;i=i+1) cin>>a[i];
	long long c=a[2]-a[1];
	for(int i=2;i<=n;i=i+1){
		if(a[i]-a[i-1]!=c){
			bj1=1;
			break;
		}
	}
	if(bj1==0){
		for(int j=2;j<=n;j=j+1){
			mins=1e18;bj=0;
			dfs(1,j,0);
			if(bj==1) ans+=1;
			if(ans==1) last=j;
		}
		long long sum=n-last+1;
		cout<<sum*ans<<endl;
		return;
	}
	for(int i=1;i<=n;i=i+1){
		for(int j=i+1;j<=n;j=j+1){
			mins=1e18;bj=0;
			dfs(i,j,0);
			if(bj==1) ans+=1;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


*/

