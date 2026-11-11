#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int f=0,n,m;
long long a[N],ans,mx=-1;
void dfs(int k,int cnt,long long sum){
	if(cnt>=m){
		ans=max(ans,sum);
		return ;
	}
	if(k>n||sum==0){
		return ;
	}	
	if(a[k]!=0)dfs(k+1,cnt+1,(sum&a[k]));
	dfs(k+1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mx<a[i]){
			mx=a[i];
			f=i;
		}
	}
	a[f]=0;
	if(m==1){
		cout<<mx;
		return 0;
	}
	dfs(1,1,mx);
	cout<<ans;
	return 0;	
}
