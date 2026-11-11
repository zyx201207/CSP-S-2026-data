#include<bits/stdc++.h>
using namespace std;
#define int long long
int ai[500010],ans[300010],js[500010];
signed lst[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int f=1;
	for(int x=1;x<=n;x++){
		cin>>ai[x];
		if(ai[x]<ai[x-1])f=0;
	}
	if(f){
		for(int x=1;x<=n;x++){
			if(ai[x]!=ai[x-1])ans[ai[x-1]]=x-1;
		}
		ans[m]=n;
		for(int x=1;x<=m;x++){
			cout<<ans[x]<<' ';
		}
	}
	else{
		for(int x=1;x<=n;x++){
			if(!js[x]){
				int lft=0,t=0;
				memset(lst,0,sizeof lst);
				for(int y=x;y<=n;y++){
					if(lst[ai[y]]){
						int k=lst[ai[y]];
						for(int z=1;z<=m;z++){
							if(lst[z]>=k)lft--,lst[z]=0;
						}
					}lst[ai[y]]=y;lft++;
					if(lft==1&&js[y]==0)js[y]=1,t++;
				}
				for(int x=1;x<=m;x++){
					ans[x]+=t*bool(lst[x]);
				}
			}
		}for(int x=1;x<=m;x++){
			cout<<ans[x]<<' ';
		}
	}
	return 0;
}
