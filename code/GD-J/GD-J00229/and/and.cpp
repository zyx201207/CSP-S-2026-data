#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005
int n,m,a[N],ans,pos,b[N],vis[N];
void dfs(int cnt,int num,int d){
	if(cnt==m){
		ans=max(ans,num);
		return;
	}
	if(d==n)return;
	dfs(cnt+1,num&a[d],d+1);
	dfs(cnt,num,d+1);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++)cin>>a[i],pos=max(pos,a[i]);
	sort(a,a+n);
	pos=0;
	for(int i=0; i<n; i++) {
		int k=a[i],cnt;
		while(k>0) {
			k/=2;
			cnt++;
		}
		b[i]=cnt;
	}
	if(n<=20&&m>2){
		dfs(0,INT_MAX,0);
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			pos=max(pos,a[j]&a[i]);
		}
	}
	cout<<pos;
	return 0;
}
