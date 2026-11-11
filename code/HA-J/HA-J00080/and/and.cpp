#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,cnt[30],sum,ans;
bool vis[200005],is,v[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=30;j++)
			if((a[i]>>j)&1)cnt[j]++;
	for(int j=30;j>=0;j--){
		if(cnt[j]>=m){
			int ss=0;
			memset(v,0,sizeof v);
			for(int i=1;i<=n;i++){
				if((!is||vis[i])&&((a[i]>>j)&1))ss++,vis[i]=1;else if(vis[i])v[i]=1;
			}
			if(ss>=m){
				ans+=(1<<j);
				for(int i=1;i<=n;i++)if(v[i])vis[i]=0;
			}
			is=1;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
