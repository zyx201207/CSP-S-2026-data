#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],vis[200005];
long long mx,cnt,ans=INT_MIN;
void dfs(int id,int x){
	if(x==m){
		long long sum=0,f=1;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				if(f)sum=a[i];
				else sum&=a[i];
				f=0;
			}
		}
		ans=max(ans,sum);
		return ;
	}
	if(id==n+1)return ;
	vis[id]=1;
	dfs(id+1,x+1);
	vis[id]=0;
	dfs(id+1,x);
}
bool check(){
	for(long long i=1;i<=n;i++){
		if(a[i]!=i-1)return 0;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cnt=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=2;i<=n;i++){
		cnt&=a[i];
	}
//	if(check()){
//		cout<<0;
//		return 0;
//	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<cnt;
		return 0;
	}
	if(m==2){
		mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx;
		return 0;
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
} 

