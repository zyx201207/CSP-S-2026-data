# include<bits/stdc++.h>
# define int long long
using namespace std;
int n,k,ip1,ip2,ch[33],fa[100001],dep[100001],dis[33],ans,c,t;
vector<int>ege[100001];
void bd(int x){
	for(int i:ege[x])if(i!=fa[x])dep[i]=dep[x]+1,fa[i]=x,bd(i);
}
void dfs(int x,int y){
	if(x==n+1){
		if(y!=k)return;
		int ct=0;
		for(int i=1;i<=n;i++)ct+=!ch[fa[i]]&&ch[i],dis[i]=100;
		if(ct>2)return;
		queue<int>A;
		for(int i=1;i<=n;i++)if(ch[i])A.push(i),dis[i]=0;
		while(!A.empty()){
			int x=A.front();A.pop();
			for(int i:ege[x])if(dis[i]>dis[x]+1)dis[i]=dis[x]+1,A.push(i);
		}
		int ans2=0;
		for(int i=1;i<=n;i++)ans2=max(ans2,dis[i]);
		ans=min(ans,ans2);
		return;
	}
	ch[x]=0,dfs(x+1,y),ch[x]=1,dfs(x+1,y+1);
}
void sol(){
	cin>>n>>k;//k>=2
	for(int i=1;i<=n;i++)ege[i].clear();
	for(int i=1;i<n;i++)cin>>ip1>>ip2,ege[ip1].push_back(ip2),ege[ip2].push_back(ip1);
	if(c==13||c==14){
		int m=(n-1)/2;
		if(k>=n)return cout<<0,void();
		if(k>=m)return cout<<1,void();
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(4*mid+k>=m)r=mid;
			else l=mid+1;
		}
		cout<<l+1<<"\n";
		return;
	}
	if(n<=10){
		ans=100,fa[1]=0,bd(1),dfs(1,0);
		cout<<ans<<"\n";
		return;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)sol();
}
