#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010];
int w[200010];
void dfs(int st,int step){
	if(step==m+1){
		int s=w[1];
		for(int i=2;i<=m;i++){
			s&=w[i];
		}
		ans=max(ans,s);
		return;
	}
	for(int i=st;i<=n;i++){
		w[step]=a[i];
		dfs(i+1,step+1);
		w[step]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<0;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int s;
			if(i==1)s=a[2];
			else s=a[1];
			for(int j=2;j<=n;j++){
				if(i==j)continue;
				if(i==1&&j==2)continue;
				s&=a[j];
			}
			ans=max(ans,s);
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
