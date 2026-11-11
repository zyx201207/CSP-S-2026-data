#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t;
int x[2000005];
int n,d;
int lim[2000005];
vector<int> e[2000005];
int dis[2000005];
int pre[2000005];
int inq[2000005];
int cnt[2000005];
int du[20000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			if(n==1){
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int md=d/(x[2]-x[1]);
			int dm=2*md-1;
			cout<<max(0ll,n-dm)<<endl;
		}
	}
	if(c<=6){
		while(t--){
			cin>>n>>d;
			//cout<<n<<" "<<d<<"!!!!"<<endl;
			if(n==1){
				cout<<0<<endl;
				continue;
			}
			x[n+1]=2e18;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int tar=1;
			//cout<<endl;
			for(int i=1;i<=n;i++){
				int l=i,r=n;
				while(l<r){
					int mid=(l+r+1)/2;
					//cout<<l<<" "<<mid<<" "<<r<<" "<<x[mid]-x[i]<<" "<<d<<endl;
					if(x[mid]-x[i]<=d)l=mid;
					else r=mid-1;
				}
				//cout<<endl;
				lim[i]=l;
			}
			for(int i=1;i<=n;i++){
				//cout<<i<<" "<<lim[i]<<endl;
				for(int j=i+1;j<=lim[i];j++){
					e[i].push_back(j);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				memset(du,0,sizeof du);
				for(int j=i;j<=n;j++){
					for(int  k=0;k<e[j].size();k++){
						du[e[j][k]]++;
					}
				}
				queue<int> q;
				q.push(i);
				memset(dis,0x3f,sizeof dis);
				memset(cnt,0,sizeof cnt);
				cnt[i]=1;
				dis[i]=0;
				while(!q.empty()){
					int top=q.front();
					q.pop();
					for(int j=0;j<e[top].size();j++){
						if(dis[e[top][j]]>dis[top]+1){
							dis[e[top][j]]=dis[top]+1;
							cnt[e[top][j]]=cnt[top];
							if(e[top][j]==4){
								//cout<<top<<"->"<<4<<" "<<dis[top]+1<<" "<<cnt[e[top][i]]<<endl;
							}
						}
						else if(dis[e[top][j]]==dis[top]+1){
							cnt[e[top][j]]+=cnt[top];
							if(e[top][j]==4){
								//cout<<top<<"->"<<4<<" "<<dis[top]+1<<" "<<cnt[e[top][i]]<<endl;
							}
						}
						du[e[top][j]]--;
						if(!du[e[top][j]]){
							q.push(e[top][j]);
						}
					}
				}
				for(int i=1;i<=n;i++){
					//cout<<cnt[i]<<" ";
					if(cnt[i]==2){
						ans++;
					}
				}
				//cout<<endl;
			}
			cout<<ans<<endl;
			for(int i=1;i<=n;i++){
				e[i].clear();
			}
				
		}
			
	}
	return 0;
}

/*
0 2 
5 3 
-2 -1 0 1 2 
6 2 
-4 -3 -2 -1 3 6 
*/
