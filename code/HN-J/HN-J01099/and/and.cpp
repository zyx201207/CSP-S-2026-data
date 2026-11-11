#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[200005],n,m,ans,a[200005];
void dfs(int x,int s){
	if(s>m){
		int sum=f[1];
		for(int i=2;i<=m;i++) sum&=f[i];
		ans=max(ans,sum);
		return;
	}
	if(x>n)return;
	f[s]=a[x];
	dfs(x+1,s+1);
	dfs(x+1,s);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn=0,s=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
		if(i==1)s=a[i];
		else s&=a[i];
	}
	if(m==1){
		cout << maxn;
		return 0;
	}
	else if(m==n){
		cout << s;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans=max(ans,(a[i]&a[j]));
		}
		cout << ans;
		return 0;
	}
	else{
		dfs(1,1);
		cout << ans;
	}
	return 0;
}
/*
100+100+50
Trick||Treat!!!
while(1) RP++; 
*/

