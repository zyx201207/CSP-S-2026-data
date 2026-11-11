#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,b[200010];
void dfs(long long num,long long cnt,long long k){
	if(k==m){
		ans=max(ans,cnt);
		return;
	}if(num>n) return ;
	for(long long i=1;i<=n;i++){
		if(b[i]==0){
//			long long cnt1=cnt&a[i];
//			cout<<cnt<<" "<<a[i]<<" "<<cnt1<<"\n";
			b[i]=1;
			dfs(num+i,cnt&a[i],k+1);
			b[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		b[o]=1;
		dfs(o,a[o],1);
	}cout<<ans;
	return 0;
}