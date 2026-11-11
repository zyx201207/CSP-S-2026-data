#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans=INT_MIN;
bool v[200005];
void dfs(int p,int ii,int num){
	int t=num;
	if(p==m){
		ans=max(ans,num);
		return;
	}
	for(int i=ii;i<=n;i++){
		if(ii==1){
			num=a[i];
		}
		dfs(p+1,i+1,num&a[i]);
		num=t;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,a[1]);
	cout<<ans;
	return 0;
} 
