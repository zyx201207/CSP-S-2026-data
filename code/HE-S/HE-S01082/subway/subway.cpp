#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k[505],a[505][1005],t[505][1005],s[1005][22],tmp[1005],lo[505][1005];
long long w[500005],ans;
void dfs(int g,int h,long long time,int lastline){
	if(g==h){
		if(time<ans) ans=time;
	}
	for(int i=1;i<=tmp[g];i++){
		for(int j=lo[i][g]+1;j<=k[i];j++){
			if(i==lastline) dfs(a[i][j],h,time,i);
			else dfs(a[i][j],h,time+t[i][lo[i][g]]+t[i][j],i);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;i<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]][++tmp[a[i][j]]]=i;
			lo[i][a[i][j]]=j;
		}
	}
	while(q--){
		ans=LONG_LONG_MAX;
		cin>>x>>y;
		long long time=w[x]+w[y];
		dfs(x,y,time,1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
