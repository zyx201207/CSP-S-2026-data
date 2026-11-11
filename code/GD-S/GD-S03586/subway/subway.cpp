#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
//测试编号、地铁数、地铁站数、每个地铁站最多被几条线路经过，出行计划数 
ll w[500005];
ll r[100005][2];
ll ting[25][500005]={0};
//bool begin[25];//貌似没用
//bool end[25];
//bool link[25][25];//找每条线和谁联系 
//void fin(){
//	for(ll i=1;i<=m;i++){
//		for(ll j=1;j<=n;j++){
//			if(ting[i][j]){
//				link[i][j]=true;
//			} 
//		}
//	}
//}
ll dfs(ll x,ll y,ll cnt){
//	begin=ting[i][r[1]];
//	end=ting[i][r[0]];
//	order=begin->end;
//	such as b=2,e=1,
//	want to 2->1;
//	dfs全部可能路径选择最小
	if(ting[x][y]==0){
		return 0;
	} 	
	for(ll i=x;i<=n;i++){
		if(ting[i][r[cnt][0]]&&ting[i][r[cnt][1]]){
			for(ll j=y;j<=r[cnt][1];j++){
				ting[i][j]=0;
			}
			return ting[i][r[cnt][0]]+ting[i][r[cnt][1]];//起始点厅到台，终点台到厅 
			
		}else{
			return min(dfs(x+1,y,cnt),dfs(x,y+1,cnt));
		} 
	}

	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
//	for(ll i=1;i<=n;i++){
//		ll total;
//		cin>>total;
//		for(ll j=1;j<=total;j++){
//			ll sta;
//			cin>>sta;
//			ting[i][sta]=true;
//			cin>>a[i][sta];
//		}
//	}
	for(ll i=1;i<=n;i++){
		ll total;
		cin>>total;
		for(ll j=1;j<=total;j++){
			ll sta;
			cin>>sta;
			cin>>ting[i][sta];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cout<<ting[i][j]<<' ';
			if(j==m){
				cout<<'\n';
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll ans=10000006;
		cin>>r[i][0]>>r[i][1];
		for(ll j=0;j<=n;j++){
			ans=w[r[i][0]]+w[r[i][1]]+min(ans,dfs(r[i][0]+j,1,i));
		}
		cout<<ans<<'\n';
	}
	
//	for(){
//		ll ans=0;
//		if(!a[i][r[0]]){
//			ans+=w[r[0]];      

//			if(a[i][r[1]]==0){
//				for(ll j=i+1;j<=)
//				if(a[i][j]&&a[i+1][j]){
//					ans+=a[i][j];
//					ans+=a[i+1][j];
//					if(a[i+1][r[1]]){
//						ans+=a[i+1][r[1]];
//						ans+=w[r[1]];
//					}
//				}
//			}
//		}
//		
//	}
	return 0;
}
