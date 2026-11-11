#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,p,q) for(ll i=p;i<=q;i++)
#define disrep(i,p,q) for(ll i=p;i>=q;i--)
ll n,m,ans,tj;
ll N=0x3f3f3f3f; 
ll ztot[1010];

struct imf{
	ll first;
	ll second;
}mapp[1010];
//存储最优解和对应的线路是什么 
ll xianlu[1010][1010];
//存储地铁线路相关信息 

//目标：减少步行时间 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll c,n,m,d,q;//n地铁线路数，m地铁站数，d 线最多经过站 ，q 站最多线 
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m){
	 	cin>>ztot[i];//地铁口到站厅需要时间
	 }
	 
	 
	 rep(i,1,n){//初始化战线步行数值最大，以便下面求最小 
	 	mapp[i].second=N;
	 	mapp[i].first=1;//默认第一条线路最少 
	 }
	 
	 rep(i,1,n){
	 	ll k;cin>>k;
	 	rep(j,1,k){
	 		ll x,y;
	 		cin>>x>>y;	
	 		xianlu[i][x]=y;//原本的，没有改变的线厅用时 
	 		ll pre_jcl=mapp[x].second;
	 		mapp[x].second=min(mapp[x].second,y);//每个站走线路的最小值 
	 		if(mapp[x].second!=pre_jcl){
	 			mapp[x].first = i;//记录最少时间线路id 
			 }
		 }
	}
	
	 while(q--){	 	 
	 	ans = 0;//初始化求的最小时间 
	 	
		ll l,r;cin>>l>>r;//出行起点终点的地铁站编号

	 	
		ans+=ztot[l];//加上地铁口到站厅时间 
	 	
		rep(k,l,r){//要经过的站点 
			ll pos=k+1;
			ll tai_to_ting=xianlu[mapp[k].first][pos];
			while(tai_to_ting==0&&pos<=r){
				pos++;
			} 
			tai_to_ting=xianlu[mapp[k].first][pos];
	 		ans+=mapp[k].second+tai_to_ting;//最少用时和当前线路的站台到站厅时间 
	 		
	 }
	    ans+=ztot[r];//最后一站：站厅到地铁口用时	 		 		 		 	
	    cout<<ans<<"\n";
	    
	 	
	}
	 return 0;
}
