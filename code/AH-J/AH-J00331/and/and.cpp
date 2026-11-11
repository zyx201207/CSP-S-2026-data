#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans;
void dfs(int x,int t,long long s){
	if(t==m){
		ans=max(ans,s);
		return;
	}
	if(x>n)return;
	dfs(x+1,t+1,s&a[x]);
	dfs(x+1,t,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==n){
		long long ggb=a[1];
		for(int i=2;i<=n;i++){
			ggb=ggb&a[i];
			if(ggb==0){
				cout<<0;
				return 0;
			}
		}
		cout<<ggb;
		return 0;
	}
	for(int i=1;i<=n;i++)dfs(i+1,1,a[i]);
	cout<<ans;
}
