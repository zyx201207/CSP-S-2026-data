#include<bits/stdc++.h>
using namespace std;
int n,m,mm[10005],ans=-INT_MAX,a[10005],vis[10005];
void dfs(int r,int sum){
	if(r>m){
		if(ans<sum){
			ans=sum;
//			cout<<'j';
//			for(int i=1;i<r;++i){
//				cout<<mm[i]<<' ';
//			}
//			cout<<endl;
//			cout<<ans<<endl;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		int cnt;
		if(r==1){
			cnt=a[i];
		}else{
			cnt=sum&a[i];
		}
		if(vis[i]) continue;
		vis[i]=1;
		mm[r]=i;
		dfs(r+1,cnt);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
//	sort(a+1,a+1+n);
	if(m==1){
		int ans=-INT_MAX;
		for(int i=1;i<=n;++i){
			ans=max(ans,a[i]);
		}
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;++i){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;++i){
			int cnt=a[i];
			for(int j=i+1;j<=n;++j){
				cnt&=a[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	dfs(1,-1);
	cout<<ans;
	return 0;
}
