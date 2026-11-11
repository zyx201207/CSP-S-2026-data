#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
void dfs(long long p,long long x,long long sum){ //选到第p个数，选了x个数，合为sum 
	if(x==m){
		ans=max(ans,sum);
		return ;
	}
	if(p>n){
		if(x==m){
			ans=max(ans,sum);
		}
		return ;
	}
	if(sum<ans&&sum!=-1)return ;
	if(sum==-1){
		dfs(p+1,x+1,a[p]);
	}
	else{
		dfs(p+1,x+1,sum&a[p]);
	}
	dfs(p+1,x,sum);
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
	if(n<=26)dfs(1,0,-1);
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else dfs(1,0,-1);
	cout<<ans;
	return 0;
}
