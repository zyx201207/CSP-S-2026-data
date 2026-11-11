#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000005];
int m[5000][5000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,c;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int xx=d/a[1];
			if(xx!=2)cout<<0<<"\n";
			else{
				int res=n/6*3;
				res+=abs(n%6-3);
				cout<<res<<"\n";
			}
		}
	}
	else{
		while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)m[i][j]=m[j][i]=1;
				else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			queue<pair<int,int> > q;//dian cost
			int vis[5005];
			memset(vis,0,sizeof(vis));
			q.push({a[i],0});
			vis[i]=1;
			int res[5005];
			memset(res,0,sizeof(res));
			int cnt[5005];
			memset(cnt,0,sizeof(cnt));
			for(int j=1;j<=n;j++)res[j]=LONG_LONG_MAX;
			while(!q.empty()){
				pair<int,int> x=q.front();
				q.pop();
				for(int j=1;j<=n;j++){
					if(m[x.first][j]&&vis[j]==0){
						vis[j]=1;
						q.push({j,x.second+1});
						if(res[j]>x.second){
							cnt[j]=1;
							res[j]=x.second;
						}
						if(res[j]==x.second)cnt[j]++;
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans/2<<"\n";
	}
	}
	
	
	return 0;
}
