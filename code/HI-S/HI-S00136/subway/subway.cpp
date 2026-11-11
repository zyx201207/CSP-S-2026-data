#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
	ll c,n,m,d,q;cin>>c>>n>>m>>d>>q; 
	/**
	测试点编号c、地铁线路数n、
	地铁站数m、每个地铁站最多被d条线路经过，
	以及出行计划数q
	**/ 
	vector<ll>w(m+10);
    for(ll i=1;i<=m;i++)cin>>w[i];//地铁口->大厅 time
    
    
    	vector<vector<pair<ll,ll> > >station(m+10);
    for(ll i=1;i<=n;i++){ 
		ll k;cin>>k;
    for(ll j=1;j<=k;j++){
            ll a,t;cin>>a>>t;
			
			station[a].push_back({i,t});
        }
    }
    
    ll M=1e30;
    
    vector<vector<ll> > dt(n+1,vector<ll>(n+10,M));
    
    
	for(ll i=1;i<=n;i++)dt[i][i]=0;
	
	for(ll v=1;v<=m;v++){ 
        ll s=(int)station[v].size();
        for(int p=0;p<s;p++){ 
            ll i=station[v][p].first;
            ll ti=station[v][p].second;
            

            for(ll q1=p+1;q1<s;q1++){ 
                ll j=station[v][q1].first;
                if(i==j)continue; 
                 
                ll tj=station[v][q1].second;
                ll h=ti+tj;  
				if(h<dt[i][j])dt[i][j]=dt[j][i]=h;
            }
        }
    }

    for(ll k=1;k<=n;k++){ 
        for(ll i=1;i<=n;i++){ 
            if(dt[i][k]==M)continue;
            for(ll j=1;j<=n;j++){ 
                if (dt[k][j]==M)continue;
                ll dd=dt[i][k]+dt[k][j]; 
                if(dd<dt[i][j]){ 
                dt[i][j]=dd;
                } 
            }      
        } 
    }   
		for(int r=1;r<=q;r++){
        ll x,y;cin>>x>>y; 
        ll cnt=M; 
      	for(int px=0;px< station[x].size();px++){
            ll i=station[x][px].first;
            ll tx=station[x][px].second; 
              
            for(int py=0;py<station[y].size();py++){
                ll j=station[y][py].first; 
                ll ty=station[y][py].second;    
                   
                if(dt[i][j]==M) continue;    
                
                ll sum=tx+dt[i][j]+ty;
                if(sum<cnt)cnt=sum;
            }   
        }  
		 
		ll ans=w[x]+cnt+w[y];
        cout<<ans<<endl;
    }
 
	
  
    return 0;
}
