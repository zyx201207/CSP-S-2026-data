#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
typedef long long ll;
ll c,n,m,d,q;
struct node{
	vector<pair<ll,ll> > vc;
	//一共可通往哪几种车，换乘时间  
	vector<pair<ll,ll> > ddd;
	//这种车在哪几个站点停，本车在那里的换程时间  
}arr[N];
struct ncd{
	ll cz;
	vector<pair<ll,ll> > vc;
}dtz[M];//这个站点有哪几种车,换成时间分别是  
ll dp[N][N];//i-j的最短路  
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>dtz[i].cz;
		//进出站点的用时  
	}
//	cout<<"1\n";
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
//		经过的地铁站数 
		for(ll j=1;j<=k;j++){
			ll p,t;cin>>p>>t;
//	经过的第 j 个地铁站，到第 i 条线的站台需要的时间 
			arr[i].ddd.push_back({p,t});
			dtz[p].vc.push_back({i,t});
		}
	}
//	cout<<"2\n";
	for(ll i=1;i<=m;i++){
		for(pair<ll,ll> p:arr[i].ddd){
//	p: 这种车在哪几个站点停，本车在那里的换程时间 
			for(pair<ll,ll> pt:dtz[p.first].vc){
		//pt: 站点p.first有哪几种车,换成时间分别是  
				if(pt.first==i) continue;
				arr[i].vc.push_back({pt.first,pt.second+p.second});
//				cout<<p.first<<" "<<pt.first<<" "<<pt.second+p.second<<"ooo\n";
		//一共可通往哪几种车，换乘时间 
			}
		}
	}
//	cout<<"3\n";
	vector<pair<ll,ll> > vp;
	//去重  
	for(ll i=1;i<=n;i++){
		sort(arr[i].vc.begin(),arr[i].vc.end());
		//排序  
		vp.clear();
		ll vcft=-1,vcsc=-1;
		for(ll j=0;j<arr[i].vc.size();j++){
			if(arr[i].vc[j].first!=vcft){
				if(vcft!=-1){
					vp.push_back({vcft,vcsc});
					vcft=arr[i].vc[j].first;
					vcsc=arr[i].vc[j].second;
				}
				else{
					vcft=arr[i].vc[j].first;
					vcsc=arr[i].vc[j].second;
				}
			}
			else{
				vcsc=(arr[i].vc[j].second,vcsc);
			}
		}
		vp.push_back({vcft,vcsc});
		arr[i].vc=vp;
	}
//	cout<<"4\n";
	for(ll i=1;i<=n;i++){
//		cout<<i<<"pu\n";
		for(pair<ll,ll> j:arr[i].vc){
//			cout<<j.first<<" "<<j.second<<"pt \n";
			dp[i][j.first]=j.second;
			dp[j.first][i]=j.second;
		}
//		cout<<i<<"pv\n";
		for(ll j=1;j<=n;j++){
			if(i==j) dp[i][j]=0;
			else if(dp[i][j]==0){
				dp[i][j]=INT_MAX;
				dp[j][i]=INT_MAX;
			}
		}
	}
//	cout<<"5\n";
	//floyd 由此开始  
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[k][i]);
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(pair<ll,ll> j:arr[i].vc){
//			cout<<i<<" "<<j.first<<" "<<j.second<<"\n";
//		}
//	}
//	cout<<"6\n";
	for(ll i=1;i<=q;i++){
		ll x,y,ans=INT_MAX;cin>>x>>y;
		for(pair<ll,ll> pa:dtz[x].vc){
			for(pair<ll,ll> pb:dtz[y].vc){
				ans=min(ans,dp[pa.first][pb.first]+pa.second+pb.second);
			}
		}
		cout<<ans+dtz[x].cz+dtz[y].cz<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
