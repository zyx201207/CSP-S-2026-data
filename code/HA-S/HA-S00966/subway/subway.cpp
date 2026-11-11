#include<bits/stdc++.h>


using namespace std;
typedef long long ll;



const ll MM = 500006;
ll c,n,m,q,d;
ll ans=0;
ll ting[MM][26];//ddao mei tiao xian shi jian
bool vis[MM];
ll kk[MM];//xian
ll fm,tar;
ll w[MM];
void dfs( ll zhan,ll xian,ll time){
	if(vis[zhan])return;
	time+=ting[zhan][xian];
	vis[zhan]=1;
	if(zhan == tar) ans=min(ans,time+w[tar]);
	for(ll i=1;i<=20;i++){
		if(ting[zhan][i]!=0){
			for(ll j=1;j<=m;j++){
				if(ting[j][i]!=0){
					dfs(j,i,time+ting[j][i]);
				}
			}
		}
	}
	
}



int main(){
	
	
	freopen("subway1.in" , "r" , stdin);
	//freopen("subway.out" , "w" , stdout);
	cin >>c >> n >> m >> d >> q;
	//cout<<"/"<<endl;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		
		cin >> kk[i];
		for(ll j=1;j<=kk[i];j++){
			ll zz;
			cin >> zz;
			cin >> ting[zz][j];
			
		}
		
		
    }
	
	
	
	while(q--){
		ans=MM;
		memset(vis,0,sizeof(vis));
		
		cin >> fm >> tar;
		for(ll i=1;i<=20;i++){
			if(ting[fm][i]!=0)dfs(fm,i,w[fm]);
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
