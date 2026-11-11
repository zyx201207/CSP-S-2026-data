#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=2e6+10;
int C,T;
int n,D;
int a[N];
vector<int> e[5010];
signed d[5010][5010][2];
bool flag[5010][5010];
void dijkstra(int st){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,st});
	while(q.size()){
		int di=q.top().first,u=q.top().second;
		q.pop();
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(d[st][v][0]>di+1){
				flag[st][v]=0;
				d[st][v][1]=d[st][v][0];
				d[st][v][0]=di+1;
				q.push({d[st][v][0],v});
			}else if(d[st][v][0]==di+1){
				if(d[st][v][0]==d[st][v][1]){
					flag[st][v]=0;
					q.push({d[st][v][0],v});
				}else
				{
					flag[st][v]=1;
					d[st][v][1]=d[st][v][0];
					q.push({d[st][v][0],v});
				}
			}else if(d[st][v][1]>di+1){
				d[st][v][1]=di+1;
				q.push({d[st][v][1],v});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	if(C<=10){
		while(T--){
			memset(flag,0,sizeof flag);
			cin>>n>>D;
			for(int i=1;i<=n;i++)
				e[i].clear();
			for(int i=1;i<=n;i++)
				cin>>a[i];
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
				
					if(a[j]<=a[i]+D)
						e[i].push_back(j);
					else
						break;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j][0]=d[i][j][1]=N;
			for(int i=1;i<=n;i++)
				dijkstra(i);
			int res=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(flag[i][j])
						res++;
			cout<<res<<endl;
		}
	}else if(C<=12){
		while(T--){
			cin>>n>>D;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			int tmp=0;
			for(int j=2;j<=n;j++)
				if(a[j]<=a[1]+D)
					tmp=j-1;
				else
					break;
			if(tmp<=1)
				cout<<0<<endl;
			else
				cout<<max((int)0,n-(2*tmp-1))<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
