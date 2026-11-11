#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
bool vis[1000005],vis2[1000005];
vector<int>ve[1000005];
queue<pair<int,int> >q;
priority_queue<int,vector<int>,greater<int>>pq;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			ve[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		int mn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
			while(!q.empty())q.pop();
			q.push({i,0});
			vis[i]=1;
			int cnt=0,x=0;
			while(!pq.empty())pq.pop();
			pq.push(0);
			while(!q.empty()){
				pair<int,int> h=q.front();
				//cout<<h.first<<" "<<h.second<<"\n";
				q.pop();
				cnt++;
				if(cnt==m){//pq.pop();
					x=h.first;
				//	mn=min(mn,h.second+pq.top());
				//	cout<<i<<" "<<h.second<<" "<<pq.top()<<"\n";
					break;
				}
				for(int i2=0;i2<ve[h.first].size();i2++){
					if(!vis[ve[h.first][i2]]){
						vis[ve[h.first][i2]]=1;
						q.push({ve[h.first][i2],h.second+1});
						pq.push(h.second+1);
						if(pq.size()>2)pq.pop();
					}
				}
			}
			for(int j=1;j<=n;j++){
				vis2[j]=0;
		//		cout<<vis[j]<<" ";
			}
	//		cout<<"\n";
			while(!q.empty())q.pop();
			q.push({x,0});
			vis2[x]=1;
			cnt=0;
			while(!q.empty()){
				pair<int,int> h=q.front();
				q.pop();
	//			cout<<h.first<<" "<<h.second<<" "<<vis2[h.first]<<" "<<cnt<<"\n";
				cnt++;
				if(cnt==m){
				mn=min(mn,h.second);
				break;	
				}
				for(int i2=0;i2<ve[h.first].size();i2++){
					if(!vis2[ve[h.first][i2]]&&vis[ve[h.first][i2]]){
						vis2[ve[h.first][i2]]=1;
			//			cout<<"____________"<<ve[h.first][i2]<<"\n";
						q.push({ve[h.first][i2],h.second+1});
					}
				}
			}
		//	cout<<"\n\n\n";
		}
		cout<<mn<<"\n";
	}
	return 0;
}
