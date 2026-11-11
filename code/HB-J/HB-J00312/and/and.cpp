#include<bits/stdc++.h>
using namespace std;
long long n,m,p[200005],f[200005],ans;
void dfs(int x){
	if(x==0){
		long long j=0,cnt;
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				if(j==0){
					cnt=p[i];
					j++;
					continue;
				}
				cnt=(cnt&p[i]);
			}
		}
		ans=max(ans,cnt);
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			continue;
		}
		f[i]=1;
		dfs(x-1);
		f[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(m==1){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(p[i],maxn);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					long long y=(p[i]&p[j]);
					maxn=max(maxn,y);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=p[1];
		for(int i=2;i<=n;i++){
			ans=(ans&p[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			long long y=INT_MAX;
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				y=(y&p[j]);
			}
			maxn=max(y,maxn);
		}
		cout<<maxn;
		return 0;
	}
	dfs(m);
	cout<<ans;
	return 0;
}
