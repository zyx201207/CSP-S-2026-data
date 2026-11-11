#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,ans,n,d,f[2000010],g[2000010],a[2000010],w[2000010];
/*void dfs(int x){
	for(int i=0;i<vc[x].size();i++){
		int u=vc[x][i];
		dfs(u);
	}
	for(int i=f[x];i;i=f[i]){
		if(f[i]==0)break;
		for(int j=i+1;j<f[i];j++){
			if(a[j]!=i)ans++;
		}
		if(a[f[i]]!=i){
			
		}
	}
}*/
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	//c=11;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>w[i];
			f[i]=0;
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12){
			int cd=d/(w[2]-w[1]);
			if(cd==0||cd==1){
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+2*cd-1<=n)ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(i==1){
				a[i]=i;
			}
			else{
				if(w[1]>=w[i]-d){
					a[i]=1;
				}
				else{
					int x=lower_bound(w+1,w+n+1,w[i]-d)-w;
					a[i]=x;
				}
			}
			if(i==n){
				f[i]=n;
				continue;
			}
			if(w[n]<=w[i]+d){
			//	cout<<i<<" "<<n<<endl;
				//vc[n].push_back(i);
				f[i]=n;
				continue;
			}
			int x=lower_bound(w+1,w+n+1,w[i]+d)-w;
			if(w[x]>w[i]+d){
				x--;
				if(x==i){
					f[i]=i;
					continue;
				}
				//vc[x].push_back(i);
				f[i]=x;
			}
			else{
			//	vc[x].push_back(i);
				f[i]=x;
			}
		}
		//for(int i=1;i<=n;i++){
			//cout<<i<<" "<<a[i]<<" "<<f[i]<<endl;
		//}
		for(int i=1;i<=n;i++){
			int lst=i;
			g[i]=1;
			for(int j=i+1;j<=n;j++){
				//cout<<j<<" "<<lst<<endl;
				if(g[lst]>2)break;
				if(f[lst]==lst)break;
				g[j]=0;
				if(a[j]==j)break;
				if(a[j]<=i){
					g[j]=1;
					if(j==f[lst])lst=j;
					continue;
				}
				if(a[j]<=lst){
					if(lst-a[j]+1>2){
						g[j]=3;
						if(j==f[lst])lst=j;
						continue;
					}
					for(int k=a[j];k<=lst;k++){
						g[j]+=g[k];
					}
					if(g[j]==2)ans++;
				}
				if(j==f[lst])lst=j;
			}
		}
		cout<<ans<<endl;
	/*	for(int i=n;i>=1;i--){
			if(!vis[i])dfs(i);
		}*/
	}
}
