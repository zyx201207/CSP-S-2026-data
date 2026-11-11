#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000005];
int head[305],nxt[90005],to[90005],cnt;
void add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
} 
int dis[305],res[305];
void dfs(int u,int idis){
	if(idis<dis[u])	dis[u]=idis,res[u]=1;
	else if(idis==dis[u])	res[u]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs(v,idis+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=2){
		while(t--){
			for(int i=1;i<=cnt;i++)	to[i]=0;
			for(int i=1;i<=cnt;i++)	nxt[i]=0;
			memset(head,0,sizeof head);
			cnt=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d)	add(i,j);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				memset(dis,0x3f,sizeof dis);
				memset(res,0,sizeof res);
				dfs(i,0);
				for(int j=i+1;j<=n;j++){
					if(res[j]==2)	ans++;
				}
			}
			cout<<ans<<"\n";
		}	
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[2]-a[1]>=d){
				cout<<"0\n";
				continue;
			}
			if(a[n]-a[1]<=d){
				cout<<"0\n";
				continue;
			}
			int one=a[2]-a[1],pos=d/one;
			cout<<n-pos*2+1<<"\n";
		}	
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int p;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					p=i;
					break;
				}
			}
			int ans=0;
			int posm=upper_bound(a+1+p,a+1+n,d+a[p-2])-a,posc=upper_bound(a+1+p,a+1+n,d+a[p-1])-a;
			for(int i=1;i<p;i++){
				if(a[p+2]-a[i]<=d)	continue;
				if(a[p+1]-a[i]<=d)	ans+=n-posc+1;
				else	ans+=posc-posm;
			}
			cout<<ans<<"\n";
		}		
	}
	return 0;
} 
