#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],maxn;
void dfs(int cnt,int ma,int now){
	if(cnt==m){
		maxn=max(maxn,ma);
		return;
	}
	if(now>n) return;
	if(cnt==0) ma=a[now];
	dfs(cnt+1,ma&a[now],now+1);
	if(cnt==0) ma=0;
	dfs(cnt,ma,now+1);
}
bool cmp(int p,int q){
	return p>q;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20){
		maxn=0;
		dfs(0,0,1);
	}else if(n<=2000){
		if(m==n){
			maxn=a[1];
			for(int i=1;i<=n;i++){
				maxn&=a[i];
			}
		}else if(m==2){
			maxn=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
	}else{
		sort(a+1,a+n+1,cmp);
		maxn=a[1];
		for(int i=1;i<=m;i++){
			maxn&=a[i];
		}
	}
	cout<<maxn;
	return 0;
} 
