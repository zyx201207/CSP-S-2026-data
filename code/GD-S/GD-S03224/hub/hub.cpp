#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int h[N],e[2*N],ne[2*N],idx;
void add(int x,int y){
	e[++idx]=y,ne[idx]=h[x],h[x]=idx;
}
int count(int x){
	int res=0;
	while(x){
		x&=(x-1);
		res++;
	}
	return res;
}
bool vis1[N];
int n,k;
bool flg[N];
void bfs1(int st){
	queue<int> q; q.push(st);
	vis1[st]=1;
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int j=h[t];j;j=ne[j]){
			int i=e[j];
			if(!flg[i]||vis1[i]) continue;
//			cout<<"wefd"; 
			q.push(i); vis1[i]=1;
		}
	}
}
int dis[N];
bool vis2[N];
void bfs2(){
	queue<int> q;
	memset(dis,0x3f,sizeof dis);
//	cout<<"wdfsdf"<<endl;
////	cout<<n<<"\n";
//	for(int i=1;i<=n;i++)
//		cout<<"wwwwww";
//	cout<<endl;
	for(int i=1;i<=n;i++)
		if(flg[i]) q.push(i),vis2[i]=1,dis[i]=0/*,cout<<"wegfwdg"*/;
	while(!q.empty()){
//		cout<<"wefgweg"<<endl;
		int t=q.front(); q.pop();
		for(int j=h[t];j;j=ne[j]){
			int i=e[j];
			if(vis2[i]) continue;
			q.push(i); vis2[i]=1;
			dis[i]=min(dis[i],dis[t]+1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T; cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) h[i]=0;
		for(int i=1;i<=2*n;i++) e[i]=ne[i]=0;
		idx=0;
		for(int i=1;i<n;i++){
			int x,y; cin>>x>>y;
			add(x,y),add(y,x);
		}
		int ans=1e18;
		for(int msk=0;msk<(1<<n);msk++){
			if(count(msk)!=k) continue;
			for(int i=1;i<=n;i++){
				vis1[i]=vis2[i]=0;
				if((msk>>(i-1))&1) flg[i]=1;
				else flg[i]=0;
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(!vis1[i]&&flg[i]){
					cnt++;
					bfs1(i);
				}
			}
			if(cnt>2) continue;
//			cout<<"cnt:"<<cnt<<'\n';
//			for(int i=1;i<=n;i++)
//				cout<<flg[i];
//			cout<<endl;
			bfs2();
//			for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
//			cout<<endl;
			int res=0;
			for(int i=1;i<=n;i++) res=max(res,dis[i]);
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}	
	return 0;
}


