#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+6;

int n,m,ans,maxn=-INT_MAX;
int a[N],vis[N];
void dfs(int pos,int num){
	if(pos==m){
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(pos+1,num&a[i]);
		vis[i]=0;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else if(m==n-1){
		sort(a+1,a+n+1);
		int sum1=a[1],sum2=a[2];
		for(int i=3;i<=n;i++){
			sum1&=a[i];
			sum2&=a[i];
		}
		cout<<max(sum1,sum2);
	}else{
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		cout<<ans;
	}
	return 0;
}
