#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[200005],Maxn,maxn,ans[200005];
void dfs(int x,int cnt){
	if(cnt>m){
		return ;
	}
	if(x==n+1){
		if(cnt==m){
			int sum=ans[1];
			for(int i=1;i<=m;i++){
				sum&=ans[i];
				//cout<<ans[i]<<" ";
			}
			maxn=max(maxn,sum);
			//cout<<<<endl;
			//out<<cnt<<" "<<maxn<<endl;
		}
		return ;
	}
	ans[cnt+1]=a[x];
	dfs(x+1,cnt+1);
	dfs(x+1,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else{
		dfs(1,0);
		cout<<maxn;
	}
}
