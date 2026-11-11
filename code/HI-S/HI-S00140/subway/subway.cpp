#include<bits/stdc++.h>
#define pp pair<long long,long long>
using namespace std;
vector<int>v[500005],l[500005];
int a[500005],d[500005];
bool f[500005];
priority_queue<pp,vector<pp>,greater<pp> >q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int g,n,m,z,r;
	cin>>g>>m>>n>>z>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int k,w,t;
		cin>>k>>w>>t;
		l[w].push_back(t);
		for(int j=2;j<=k;j++){
			int wi,ti;
			cin>>wi>>ti;
			v[w].push_back(wi);
			l[w].push_back(ti);
		}
	}
	for(int i=1;i<=r;i++){
		int s,t;
		cin>>s>>t;
		memset(d,0x3f,sizeof(d));
		memset(f,0,sizeof(f));
		q.push({0,s});
		while(!q.empty()){
			int dis=q.top().first;
			int xh=q.top().second;
			q.pop();
			if(xh==t){
				cout<<dis+a[s]+a[t]<<"\n";
			}
			if(f[xh]){
				continue;
			}
			f[xh]=true;
			for(int i=0;i<v[xh].size();i++){
				int to=v[xh][i];
				int len=l[xh][i+1];
				if(d[to]>l[xh][0]+len+d[xh]){
					d[to]=l[xh][0]+len+d[xh];
					q.push({d[to],to});
				}
			}
		}
	}
	return 0;
}

