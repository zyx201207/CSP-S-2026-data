#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool bf[200005];
long long ans;
void and_dfs(int num,int t,long long b){
	bf[t]=1;
	if(num>m){
		ans=max(b,ans);
		bf[t]=0;
		return;
	}
	b=b&a[t];
	for(int i=1;i<=n;i++){
		if(bf[i]==0)and_dfs(num+1,i,b);
	}
	bf[t]=0;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		and_dfs(1,i,a[i]);
	}
	cout<<ans;
}
