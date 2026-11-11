#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int maxn=0;
void dfs(int u,int sum,int cnt){
	if(u>n){
		if(cnt==m){
			maxn=max(sum,maxn);	
		}
	}else{
		dfs(u+1,sum&a[u],cnt+1);
		dfs(u+1,sum,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	//m==n
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
			if(sum==0){
				cout<<0;
				return 0;
			}
		}
		cout<<sum;
		return 0;
	}
	
	//m==2
	if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);	
			}
		}
		cout<<maxn;
		return 0;
	}
	
	//1~5
	for(int i=1;i<=(n-m+1);i++){
		dfs(1,a[i],0);
	}
	cout<<maxn;
	return 0;
}

