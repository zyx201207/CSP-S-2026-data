#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[15500];
ll mp[15500][15500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		ll op;
		cin>>op;
		for(int j=1;j<=op;j++){
			ll x,y;
			cin>>x>>y;
			mp[x][i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		ll st,ed;
		cin>>st>>ed;
		int ans=arr[st];
		ll now=st-1;
		ll pt=0,min1=INT_MAX;
		for(int j=1;j<=n;j++){
			if(mp[now+1][j]!=0 && mp[now+1][j]<min1){
				pt=j;
				min1=min(min1,mp[now+1][j]);
				//cout<<min1<<" ";
			}
			
		}
		ans+=min1;
		now++;
		//cout<<now<<" "<<ans<<endl;
		while(now<ed){
			//cout<<1;
			bool ok=0;
			int zs=now;
			for(int j=now+1;j<=ed;j++){
				if(mp[j][pt]>0){
					zs=j;
					ans+=mp[j][pt];
					ok=1;
				}
				//cout<<zs<<" "<<mp[j][pt]<<" "<<ans<<endl;
			}
			now=zs;
			if(!ok){
				ll min2=INT_MAX;
				for(int j=1;j<=n;j++){
					if(pt==j) continue;
					if(mp[now][j]!=0 && mp[now][j]<min2){
						pt=j;
						min2=min(min2,mp[now][j]);
					}
				}
				ans+=min2;
			}
			//cout<<now<<" "<<ans<<endl;
		}
		ans+=arr[ed];
		cout<<ans<<endl;
	}
	return 0;
}
