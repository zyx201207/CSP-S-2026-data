#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=0;
void dfs(int i,int cnt,long long c){
	if(cnt>m) return;
	if(cnt==m){
		ans=max(ans,c);
		return;
	}
	if(i==n+1) return;
	dfs(i+1,cnt,c);
	if(!cnt) dfs(i+1,cnt+1,a[i]); 
	else dfs(i+1,cnt+1,c&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
			cout<<ans;
			return 0;
		}
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
