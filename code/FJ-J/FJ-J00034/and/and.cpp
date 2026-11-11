#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxnn;
void dfs(int now,long long ans,long long cnt){
	if(now>n+1)return;
	if(cnt==m){
		maxnn=max(maxnn,ans);
		return; 
	}
	if(ans==0){
		dfs(now+1,a[now],cnt+1);
	}else{
		int c=ans&a[now];
		dfs(now+1,c,cnt+1);
	}
	dfs(now+1,ans,cnt);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	long long maxn=-0x3f3f3f3f;
	long long sum=a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum&=a[i];
		maxn=max(maxn,a[i]);
		if(a[i]%2==0){
			flag=1;
		}
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==n-1&&n>2000){
		long long p;
		bool f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&f==0){
				f=1;
			}else{
				p&=a[i];
			}
		}
		cout<<p;
		return 0;
	}
	dfs(1,0,0);
	cout<<maxnn;
	return 0;
}
