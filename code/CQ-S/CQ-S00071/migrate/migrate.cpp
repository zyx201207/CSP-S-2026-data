#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
	
vector<int> t[N]; 

int f[N],cnt[N],a[N];

void dfs(int x){
	
	for (int i=0;i<t[x].size();i++){
		
		int y=t[x][i];//cout<<x<<" "<<y<<"\n";
		if (f[x]+1>f[y]) continue ;

		
		if (f[x]+1==f[y]) cnt[y]++;
		else cnt[y]=1,f[y]=f[x]+1,dfs(y); 
		
		//cout<<x<<" "<<y<<" "<<cnt[y]<<" "<<f[y]<<"\n";
		
	}
	
	return ;
	
}

int vis[N];

void test(int x){
	
	vis[x]=1;
	
	for (int i=0;i<t[x].size();i++){
		
		int y=t[x][i];
		
		if (vis[y]) continue ;
		
		cout<<x<<" "<<y<<"\n";
		
		test(y);
		
	}
	
}

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	
	while (T--){
		
		for (int i=1;i<=2e6;i++) t[i].clear();
		
		int n,m;
		cin>>n>>m;
		
		for (int i=1;i<=n;i++) cin>>a[i];
		
		sort(a+1,a+1+n);
		
		for (int i=1;i<=n;i++){
			
			int j=i+1;
			
			while (a[i]+m>=a[j]&&j<=n){
				
				t[i].push_back(j);
				//cout<<i<<" "<<j<<"\n"; 
				j++;
				
			}
			
		}
		
		//memset(vis,0,sizeof(vis));
		//test(1);
		
		int ans=0;
		
		for (int i=1;i<=n;i++){
			
			memset(f,0x3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			f[i]=0,cnt[i]=1,dfs(i);
			
			//if (i==1) cout<<"\n";
			
			for (int j=1;j<=n;j++) {
				
				//if (j==1)
					//cout<<f[j]<<" "<<cnt[j]<<'\n';
				
				if (cnt[j]==2) ans++;
				
			}
			
		}
		
		cout<<ans<<"\n";
		
	}
	
	return 0;
	
}
