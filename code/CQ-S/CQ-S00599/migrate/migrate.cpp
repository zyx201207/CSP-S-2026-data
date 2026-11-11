#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int x[2000005];
int mi,sum;
inline void dfs(int L,int R,int u,int s){
	if(s>mi)return ;
	if(u==R){
		if(mi==s)sum++;
		else mi=s,sum=1;
		return ;
	}
	for(int v=u+1;v<=R;v++){
		if(x[v]-x[u]>d)break;
		dfs(L,R,v,s+1);
		if(sum>2)return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;int ans=0; 
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==13||c==14){
			int u,mxl,mxr,mil,mir;
			for(int i=1;i<=n;i++)
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){u=i;break;}
			for(int i=u;i<=n;i++)
				if(x[i]-x[u-2]<=d)mxl=i;
			for(int i=u;i<=n;i++)
				if(x[i]-x[u-1]<=d)mxr=i;
			for(int i=u;i;i--)
				if(x[u+1]-x[i]<=d)mil=i;
			for(int i=u;i;i--)
				if(x[u+2]-x[i]<=d)mir=i;
			cout<<(mxr-mxl)*(mil-1)+(mir-mil)*(n-mxl)<<'\n';
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				sum=0,mi=INT_MAX;
				dfs(i,j,i,0);
				ans+=(sum==2);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
