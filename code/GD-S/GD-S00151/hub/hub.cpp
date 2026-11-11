#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int id,T,n,m,BZ,cnt; 
int ans,ans1,ans2;
int f[N],bz[N],bj[N],bk[N];
int to[N],nxt[N],head[N];
void add(int u,int v){
	cnt++;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}void search(int x,int y){
	bk[x]=BZ;
	if(bz[x]) ans2=min(ans2,y);
	for(int i=head[x];i;i=nxt[i]){
		if(bk[to[i]]==BZ) continue;
		search(to[i],y+1);
	}return ;
}void dfs(int x,int y){
	if(y>m) return ;
	if(x>n){
//		cout<<y<<" "<<m<<endl;
		int sum=0;
		for(int i=1;i<=n;i++) f[i]=i,bj[i]=0;
		for(int i=1;i<=n;i++){
			if(!bz[i]) continue;
			for(int j=head[i];j;j=nxt[j]){
				if(!bz[to[j]]) continue;
//				cout<<i<<","<<find(i)<<" "<<to[j]<<","<<find(to[j])<<endl;
				if(find(i)==find(to[j])) continue;
//				cout<<"merge\n";
				f[find(i)]=find(to[j]);
			}
		}for(int i=1;i<=n;i++){
			if(!bz[i]) continue;
//			cout<<find(i)<<" ";
			sum+=(!bj[find(i)]),bj[find(i)]=1;
		}//cout<<"sum:"<<sum<<endl;
		if(sum>2) return ;
//		cout<<123456<<endl;
		ans1=0;
		for(int i=1;i<=n;i++){
			ans2=10000000,++BZ,search(i,0);
			ans1=max(ans1,ans2);
		}//for(int i=1;i<=n;i++) cout<<bz[i];
//		cout<<" "<<ans1<<endl;
		ans=min(ans,ans1);
		return;
	}bz[x]=1;
	dfs(x+1,y+1);
	bz[x]=0;
	dfs(x+1,y);
	return ;
}void solve(){
	cin>>n>>m;
	ans=10000000,cnt=0;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}dfs(1,0);
	cout<<ans<<endl;
	return ;
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>id>>T;
	while(T--) solve();
}
