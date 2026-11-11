#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[200010];
bool b[200010];
void dfs(int t,int s){
	if(t==m){
		if(s>ans){
			ans=s;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==true){
			b[i]=false;
			if(t==0) dfs(t+1,a[i]);
			else dfs(t+1,s&a[i]);
			b[i]=true;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=true;
	} 
	dfs(0,0);
	cout<<ans;
	return 0;
}
