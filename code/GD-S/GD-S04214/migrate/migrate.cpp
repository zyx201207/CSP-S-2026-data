#include<bits/stdc++.h>
using namespace std;
int c,t,n,st[305];
long long a[2000005],d,dis;
void dfs(int now,int step,int r){
	if(now==r){
		st[step]++;
		return;
	}
	for(int i=now+1;i<=r;i++){
		if(a[i]-a[now]>d)break;
		dfs(i,step+1,r);
	}
}
bool is_ok(int l,int r){
	memset(st,0,sizeof(st));
	dfs(l,0,r);
	int i=1;
	while(i<=r-l && !st[i])i++;
	if(st[i]==2)return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		memset(a,0,sizeof(a));
		bool flag=true;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i==2)dis=a[2]-a[1];
			if(i>2 && a[i]-a[i-1]!=dis)flag=false;
		}
		if(flag){
			if(dis>=d || a[n]-a[1]<=d)printf("0\n");
			else printf("%lld\n",n-(d/dis*2)+1);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d)continue;
				if(is_ok(i,j))ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
