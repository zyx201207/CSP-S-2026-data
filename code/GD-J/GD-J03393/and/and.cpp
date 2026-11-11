#include<bits/stdc++.h>
using namespace std;
int n,m,f[200005];
long long a[200005],ans=0;
void dfs(int time,long long sum){
	if(time==0){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1) continue;
		f[i]=1;
		long long yu=0;
		if(time==m) yu=a[i];
		else yu=(sum&a[i]);
		//cout<<"yu="<<yu<<endl;
		dfs(time-1,yu);
		f[i]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	//for(int i=1;i<=n;i++) cout<<f[i];
	//cout<<endl;
	dfs(m,0);
	printf("%lld",ans);
	return 0;
} 
