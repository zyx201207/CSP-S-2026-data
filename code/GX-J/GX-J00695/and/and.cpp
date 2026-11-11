#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=INT_MIN;
int vis[25];
void dfs(int x){
	if(x>n){
		int cnt=0,sum,f=0;
		for(int i=1;i<=n;i++){
			if(f==1){
				if(vis[i]==1){
					sum=sum&a[i];
					cnt++;
				}
			}
			else if(vis[i]==1){
				sum=a[i];
				f=1;
				cnt++;
			}
		}
		if(cnt!=m)return;
		ans=max(ans,sum);
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}else if(m==2){
		int cnt=INT_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
		return 0;
	}else if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
