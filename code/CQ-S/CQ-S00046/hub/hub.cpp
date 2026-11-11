#include<bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second
int c,t,n,k,ans,dep[4005],flag[4005],l[4005],r[4005],dfx;
int g[4005],now; 
vector<int> e[4005];
void dfs(int x,int fa,int len){
//	cout<<x<<" "<<fa<<"\n";
	dep[x]=0;
	for(int i:e[x]){
		if(i==fa)continue;
		dep[i]=max(dep[i],dep[x]+1);
		dfs(i,x,len);
	}
}
void dp(int x,int fa,int len,int fdis){
	int fg=0;
	if(fdis==-1){
		if(dep[x]<len)return ;
		now--;
		for(int i:e[x]){
			if(i==fa)continue;
			dp(i,x,len,-1);
		}
		return ;
	}
	for(int i:e[x]){
		if(i==fa)continue;
		if(dep[i]<=len){
			fdis=max(fdis,dep[i]);
		}else{
			fg=1;
		}
	}
	if(!fg)return ;
	if(fdis==len){
		fdis=-2;
		now--;
	}
	for(int i:e[x]){
		if(i==fa)continue;
		dp(i,x,len,fdis+1);
	}
}
int check1(int x,int fa,int y){
	int l=0,r=n+5,mid;
	while(l<r){
		mid=l+r>>1;
		now=y;
		dep[x]=dfx=0;
		g[x]=1;
		dfs(x,fa,mid);
		dp(x,fa,mid,0);
		if(now>=0)r=mid;
		else l=mid+1;
	}
	return l;
}
int check(int x,int y,int p){
	return max(check1(x,y,p),check1(y,x,k-p));
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		ans=n+5;
		for(int i=1;i<=n;i++){
			for(int j:e[i]){
				for(int p=1,x;p<k;p++){
					x=check(i,j,p);
					ans=min(ans,x);
				}	
			}
		}
		ans=min(ans,check1(1,0,k));
		cout<<ans<<"\n";
	}
	return 0;
}
//ºÃÏñÊÇnklogµÄ 
