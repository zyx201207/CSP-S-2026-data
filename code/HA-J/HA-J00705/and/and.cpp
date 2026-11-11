#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],m,ans,s[N];
void dfs(int sum,int idx,int cnt){
	if(idx==m) {
		ans=max(ans,sum); return;
	}
	if(cnt==n) return;
	dfs(sum,idx,cnt+1);
	dfs(sum&a[cnt+1],idx+1,cnt+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		for(int i=1;i<=n-m+1;i++) dfs(a[i],1,i);
		cout<<ans;
		return 0;
	}
	else if(m==1) {
		int maxx=0;
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		int anss=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<anss;
		return 0;
	}
	else if(m==2){
		int anss=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				anss=max(anss,a[i]&a[j]);
			}
		}
		cout<<anss;
		return 0;
	}
	else if(m==n-1){
		s[1]=a[1];
		int anss=0;
		for(int i=2;i<=n;i++) s[i]=s[i-1]&a[i];
		for(int i=1;i<=n;i++) anss=max(anss,s[i]&a[i]);
		cout<<anss;
	}
}
