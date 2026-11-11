#include<bits/stdc++.h>
using namespace std;
int n,ans,a[500005],b[500005];
long long m;
int num(){
	int c=0;
	for(int i=1;i<=n;i++){
		c=max(c,b[i]);
	}
	return c;
}
void dfs(long long step){
	if(step==m){
		ans=max(ans,num());
	}
	else{
		for(int i=1;i<=n;i++){
			b[a[i]]--;
			a[i]++;
			b[a[i]]++;
			dfs(step+1);
			b[a[i]]--;
			a[i]--;
			b[a[i]]++;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
