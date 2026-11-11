#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans[200010];
int vis[200010];
int answer=-1;
void dfs(int stp){
	if(stp==m+1){
		int s=ans[1];
		for(int i=1;i<=m;i++){
			s&=ans[i];
		}
		answer=max(answer,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[stp]=a[i];
			dfs(i+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==n){
		int s1=a[1];
		for(int i=2;i<=n;i++)s1&=a[i];
		cout<<s1;
	}else if(m==2){
		int mx1=-1;
		for(int i=1;i<n;i++){
			int s2=a[i];
			for(int j=i+1;j<=n;j++){
				s2&=a[j];
				mx1=max(mx1,s2);
				s2=a[i];
			}
		}
		cout<<mx1;
	}else if(m==n-1){
		int mx2=a[2];
		for(int i=3;i<=n;i++)mx2&=a[i];
		for(int i=2;i<=n;i++){
			int s3=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i)s3&=a[j];
			}
			mx2=max(mx2,s3);
		}
		cout<<mx2;
	}else{
		dfs(1);
		cout<<answer;
	}
	return 0;
}











