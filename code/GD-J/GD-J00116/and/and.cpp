#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int p[40],a[N];
int c[40][N];
int n,m,res=0;
bool cmp(int x,int y){
	return x>y;
}
bool cmp1(int x,int y){
	int c1=__builtin_popcount(x);
	int c2=__builtin_popcount(y);
	if(c1==c2)return x>y;
	return c1>c2;
}
void dfs(int idx,int k,int ans){
	if(k==m){
		res=max(res,ans);
		return;
	}
	if(idx>=n||k>m||(n-idx)<(m-k))return;
	for(int i=idx+1;i<=n;i++){
		dfs(i,k,ans);
		dfs(i,k+1,ans&a[i]);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int inf=(1ll<<62);	
	if(n<=20){
		dfs(0,0,inf-1);
		cout<<res;
		return 0;
	}
	if(m==1){
		res=0;
		for(int i=1;i<=n;i++)res=max(res,a[i]);
		cout<<res;
		return 0;
	}
	if(n<=5000&&m==2){
		res=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)res=max(res,a[i]&a[j]);
		cout<<res;
		return 0;
	}
	if(n==m){
		res=a[1];
		for(int i=2;i<=n;i++)res=(res&a[i]);
		cout<<res;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=30;j>=0;j--){
				int w=(1ll<<j);
				if(a[i]&w){
					c[j][i]++;
					p[j]++;
				}
			}			
		}
		res=0;
		for(int i=1;i<=n;i++){
			for(int j=30;j>=0;j--)p[j]-=c[j][i];
			int ans=0;
			for(int j=30;j>=0;j--)
				if(p[j]>0)ans+=(1ll<<j);
			res=max(res,ans);
			for(int j=30;j>=0;j--)p[j]+=c[j][i];
		}
		cout<<res;
		return 0;
	}
	res=0;
	sort(a+1,a+n+1,cmp);
	int k=log2(a[m]);
	k++;
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=k;j>=0;j--){
			if(a[i]&(1ll<<j))ans+=(1ll<<j);
		}
		a[i]=ans;
	}
	sort(a+1,a+n+1,cmp1);
	res=a[1];
	for(int i=2;i<=m;i++)res=(res&a[i]);
	cout<<res;
}
