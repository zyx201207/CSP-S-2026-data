#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn=-1;
ll a[200005],b[200005];
bool vis[200005];
void dfs(ll k){
	if(k==m+1){
		ll sum=b[1];
		for(int i=2;i<=k-1;i++){
			sum&=b[i];
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[k]=a[i];
			vis[i]=1;
		}else continue;
		dfs(k+1);
		b[k]=0;
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==n){
		ll sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll s=a[i];
				s&=a[j];
				if(s>maxn)maxn=s;
			}
		}
		cout<<maxn;
	}else{
		dfs(1);
		cout<<maxn;
	}
	return 0;
}

