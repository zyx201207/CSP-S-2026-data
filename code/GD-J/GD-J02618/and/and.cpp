#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[100010];
long long f[100010];
bool v[100010];
void dfs(long long x){
	if(x>m){
		int sum=f[1];
		for(int i=1;i<=m;i++){
			sum=sum&f[i];
		}
		if(sum>ans){
			ans=sum;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			f[x]=a[i];
			dfs(x+1);
			v[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

