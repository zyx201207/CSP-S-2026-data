#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int x[N];
int dis[N];
int cnt[5001];//方案数 

void work(){
	
	
	int n,d;
	cin>>n>>d; 
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	
	/*for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<"\n";*/
	int ans=0;
	for(int j=1;j<=n;j++){
		memset(cnt,0,sizeof cnt);
		memset(dis,0,sizeof dis);
		cnt[j]=1; dis[j]=1;
		for(int i=j;i<=n;i++){
		
			int t=i;
			for(int i=t+1;i<=n;i++){
				if(x[i]-x[t]>d)break;
				if(dis[i]!=0&&dis[i]!=dis[t]+1)continue;
				dis[i]=dis[t]+1;
				
				//cout<<i<<" "<<cnt[t]<<"\n\n";
				cnt[i]+=cnt[t];
			} 
		}
		for(int i=j+1;i<=n;i++){
			//cout<<cnt[i]<<" ";
			if(cnt[i]==2)ans++;
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
	return ; 
}
signed main(){
	//海鸟只有可能一直向南飞
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	while(t--){
		work();
	}
	return 0;
}
