#include<bits/stdc++.h>
using namespace std;
bool vis[200001];
long long n,k;
long long step[200001];
long long a[200001];
long long ans=0;
void dfs(long long s){
	if(s==k+1){
		long long sum=step[1];
		for(long long i=2;i<=n;i++){
			sum=sum&step[i];
		}
		ans=max(ans,sum);
	}
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			step[s]=a[i];
			vis[i]=true;
			dfs(s++);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}