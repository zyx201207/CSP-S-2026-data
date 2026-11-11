#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
bool v[200005];
void dfs(long long cnt,long long sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(cnt+1,sum&a[i]);
			v[i]=0;
		}
	}
}


int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		dfs(0,a[i]);
	}
	cout<<ans;
	return 0;
}
