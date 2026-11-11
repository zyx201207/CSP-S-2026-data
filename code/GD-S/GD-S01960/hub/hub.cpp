#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,x,y,m,T,c,si[200005],ans,maxx=99999999,answ,vis[200005],b[200005],cnt,u;
vector <int> v[200005];
map <pair<int,int>,bool > mp;
queue <pair<int,int>> q;
void sol(int x,int f){
	//cout<<x<<endl;
	si[x]=1;
	int mx=0;
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]!=f){
			sol(v[x][i],x);
			si[x]+=si[v[x][i]];
			mx=max(mx,si[v[x][i]]);
		}
	}
	mx=max(mx,n-si[x]);
	if(mx<maxx){
		maxx=mx;
		ans=x;
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		while(!q.empty()){
			q.pop();
		}
		ans=0;
		cnt=0;
		maxx=99999999;
		cin>>n>>k;
		for(i=1;i<=n;i++){
			vis[i]=0;
			si[i]=0;
			b[i]=0;
		}
		for(i=1;i<n;i++){
			cin>>x>>y;
			if(mp[{x,y}]==0){
				v[x].push_back(y);
				v[y].push_back(x);
				mp[{x,y}]=mp[{y,x}]=1;
			}
			
		}
		sol(1,0);
		//cout<<ans<<endl;
		
		v[ans].erase(v[ans].begin());
		for(i=1;i<=n;i++){
			b[i]=v[i].size();
			if(v[i].size()==1){
				q.push({i,1});
				vis[u]=1;
			}
		}
		while(!q.empty()){
			answ=q.front().second;
			u=q.front().first;
			cnt++;
			if(n-cnt<=k){
				break;
			}
			for(i=0;i<v[u].size();i++){
				if(vis[u]==0){
					b[v[u][i]]--;
					if(b[v[u][i]]==1){
						vis[v[u][i]]=1;
						q.push({v[u][i],answ+1});
					}
				}
			}
		}
		cout<<answ<<endl;
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		mp.clear();
		cnt=0;
	}
	
	
	
	return 0;
}
