#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],maxx,b[2005];
void dfs(int idx,int cnt){
	if(cnt>m){
		return;
	}
	if(idx>n){
		return;
	}
	b[cnt]=a[idx];
	if(cnt==m){
		if(m==1){
			maxx=max(maxx,b[1]);
			return;
		}else{
			int ans=b[1]&b[2];
			for(int i=3;i<=m;i++){
				ans&=b[i];
			}
			maxx=max(maxx,ans);
			return;
		}
	}
	dfs(idx+1,cnt);
	dfs(idx+1,cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0);
		cout<<maxx;
	}else{
		if(m==1){
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			cout<<maxx;
		}else if(m==n){
			maxx=a[1]&a[2];
			for(int i=3;i<=n;i++){
				maxx&=a[i];
			}
			cout<<maxx;
		}else{
			sort(a+1,a+n+1);
			maxx=a[n]&a[n-1];
			for(int i=n-2;i>=n-m+1;i--){
				maxx&=a[i];
			}
			cout<<maxx;
		}
	}
	return 0;
}
