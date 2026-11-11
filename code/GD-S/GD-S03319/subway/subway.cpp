#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
long long c,n,m,d,qu,ww[500005],k,a[500005],t,qian[500005],minn[500505];
struct ll{
	long long v,w;
	bool operator<(const ll&x)const{
		return x.w<w;
	}
};
vector<ll>o[500505];
priority_queue<ll>q;
void dij(long long u){
	minn[u]=0;
	q.push({u,0});
	while(!q.empty()){
		long long ue=q.top().v,ww=q.top().w;
		q.pop();
		for(int i=0;i<o[ue].size();i++){
			long long ve=o[ue][i].v;
			long long dat=minn[ve];		
			if(!dat){
				minn[ve]=ww+o[ue][i].w;
				q.push({ve,ww+o[ue][i].w});
			}
			else if(ww+o[ue][i].w<dat){
				minn[ve]=ww+o[ue][i].w;
				q.push({ve,ww+o[ue][i].w});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++) cin>>ww[i];
	qian[0]=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){			
			cin>>a[j]>>t;
			o[a[j]].push_back({i+500000,t});
			o[i+500000].push_back({a[j],t});
		}
	}
	long long uu,vv;
	for(int i=1;i<=qu;i++){
		cin>>uu>>vv;
		for(int i=1;i<=m;i++) minn[i]=0;
		for(int i=1;i<=n;i++) minn[500000+i]=0;
		dij(uu);
		cout<<ww[uu]+ww[vv]+minn[vv]<<"\n";
	}
	return 0;
} 
/*
0 3 7 20 2  
8 3 6 1 7 2 9 
3 1 4 2 5 5 100 
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7 
1 6 
2 3
*/
