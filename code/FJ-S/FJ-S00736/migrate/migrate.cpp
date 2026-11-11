#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000005];
struct f{
	int v,w,nxt;
}e[2000005];
int h[500005],cnt;
void add(int u,int v,int w){
	e[++cnt]={v,w,h[u]};
	h[u]=cnt;
	return;
}
int ans,minn;
//int dfs(int now,int sumw,int end){
//	if(now==end){
//		if(sumw<minn){
//			minn=sumw;
//			ans=1;
//		}else if(sumw==minn){
//			ans++;
//		}else{
//			return 0;
//		}
//	}
//	
//	for(int i=h[now];i;i=e[i].nxt){
//		int v=e[i].v;
//		dfs(v,sumw+1,end);
//	}
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(e,0,sizeof e);
		memset(h,0,sizeof h);
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					add(i,j,1);
//					cout<<i<<" "<<j<<endl;
				}else{
					break;
				}
			}
		}
		int anss=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
//				minn=2000005;
//				dfs(i,0,j);
				int qqq=2000005;
				queue<pair<int,int> > q;
				q.push({i,0});
				while(!q.empty()){
					int u=q.front().first;
					int s=q.front().second;
//					cout<<u<<' '<<s<<endl;
					q.pop();
					if(s>qqq){
						break;
					}
					if(u==j){
						qqq=s;
						ans++;
						continue;
					}
					for(int k=h[u];k;k=e[k].nxt){
						q.push({e[k].v,s+1});
					} 
				}
				if(ans==2){
//					cout<<i<<" "<<j<<endl;
					anss++;
				}
//				cout<<endl;
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
8tps
*/
