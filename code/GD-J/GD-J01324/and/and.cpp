#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn];
int pre[maxn];
int ans=0;
void dfs(int now,int s,int x,bool ok){
	if(now==n+1){
		if(s!=0)return;
		ans=max(ans,x);
		return;
	}
	dfs(now+1,s,x,ok);
	if(s>=1){
		if(ok==false)dfs(now+1,s-1,a[now],true);
		else dfs(now+1,s-1,x&a[now],ok);
	}
}
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int c=0;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)c=a[i];
		else c&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<c;
		return 0;
	}
	if(m==2){
		int T=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				T=max(T,a[i]&a[j]);
			}
		}
		cout<<T;
		return 0;
	}
	if(n>25){
		sort(a+1,a+n+1);
		int q=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			q&=a[i];
		}
		cout<<q;
		return 0;
	}
	dfs(1,m,0,false);
	cout<<ans;
	return 0;
} 
