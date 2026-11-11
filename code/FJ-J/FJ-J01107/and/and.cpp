#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m;
long long ans=0;
void dfs(int deep,int now,long long shu){
	if(deep==m){
		ans=max(ans,shu);
		return;
	}
	for(int i=now+1;i<=n;i++){
		dfs(deep+1,i,(shu&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long num=1;
	num=(1ULL<<30)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,num);
	cout<<ans;
	return 0;
} 
