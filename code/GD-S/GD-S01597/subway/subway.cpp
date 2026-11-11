#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define mp make_pair
using namespace std;
using pr=pair<int,int>;

const int N=5e5+5;

int c,n,m,dis,q,k,x,y;
vector<pr> a[N+6000];
vector<pr> li[N];
long long w[N],d[N];
long long ans[505][505];

void dijk(int s){
	memset(d,0x3f,sizeof(d));d[s]=0;
	priority_queue<pr,vector<pr>, greater<pr> > q;
	q.push(mp(0,s));
	while(!q.empty()){
		pr f=q.top();q.pop();
		for(auto i:a[f.second]){
			if(d[i.first]>d[f.second]+i.second){
				d[i.first]=d[f.second]+i.second;
				q.push(mp(d[i.first],i.first));
			}
		}
	}
	for(int i=1;i<=n;i++) ans[s-m][i]=d[m+i];
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>dis>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ak;
			cin>>ai>>ak;
			li[ai].push_back(mp(i,ak));
			a[ai].push_back(mp(m+i,ak));
			a[m+i].push_back(mp(ai,ak));
		}
	}
	for(int i=1;i<=n;i++){
		dijk(i+m);
	}
	for(int qi=1;qi<=q;qi++){
		cin>>x>>y;
		long long ans1=1e18;
		for(auto i:li[x]){
			for(auto j:li[y]) ans1=min(ans1,ans[i.first][j.first]+i.second+j.second);
		}
		ans1+=w[x]+w[y];
		cout<<ans1<<endl;
	}
	return 0;
}
