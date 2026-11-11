#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,sum,ii,jj,ans,a[20005],aaa;
bool p;
void dfs(int s,int k){
	if(k>=ans) return;
	if(s==jj){
		ans=k;
		return;
	}
	for(int i=s+1;a[i]<=a[s]+m;i++){
		dfs(i,k+1);
	}
}

void dfss(int s,int k){
	if(p==0) return;
	if(sum>2){
		p=0;
		return;
	}
	if(s==jj){
		if(k==ans) sum++;
		return;
	}
	for(int i=s+1;a[i]<=a[s]+m;i++){
		dfss(i,k+1);
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		aaa=0;
		for(int len=3;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				ii=i;
				jj=j;
				p=1;
				sum=0;
				ans=LLONG_MAX;
				dfs(ii,0);
				ans++;
				dfss(ii,0);
				cout<<ans<<' ';
				if(sum==2){
					aaa++;
				}
			}
		}
		cout<<aaa<<endl;
	}
	return 0;
}
