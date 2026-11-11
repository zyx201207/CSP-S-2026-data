#include<bits/stdc++.h>
using namespace std;
long long c,n,l,d,q,x,y,t;
long long ans,a[5005];
pair<int,int> k[5005];
bool p[5005];
void dfs(int x,int e){
	if(e){
	if(e<k[x].first){
		k[x].first=e;
		k[x].second=0;
	}else if(e==k[x].first){
		k[x].second++;
	}else{
		return;
	}
	}
	for(int o=x+1;o<=x+d;o++){
		dfs(o,e+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(;t--;){
		ans=0;l=1;
		cin>>n>>d;
		for(long long o=1;o<=n;o++){
			a[o]=0;
		}
		for(long long o=1;o<=n;o++){
			cin>>a[o];
			y=a[o]-a[o-1];
		}
		if(c==11||c==12){
			ans=n-d/y*2+1;
		}else if(c<=10){
			for(long long o=1;o<=n;o++){
				for(long long j=1;j<=n;j++){
					k[j]={1e9,0};
				}
				dfs(o,0);
				for(long long j=1;j<=n;j++){
					if(k[j].second==1){
						ans++;
					}
					//cout<<o<<' '<<k[j].first<<' '<<k[j].second<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
