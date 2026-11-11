#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int za[500005];
bool vis[500005],kua[500005];
struct node{
	int t,xian;
};
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>za[i];
	vector<vector<node>> w(m);
	unordered_set<int> st[500];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ew,wq;
			cin>>ew>>wq;
			if(!w[ew].empty()&&!vis[ew]) vis[ew]=true;
			w[ew].push_back({wq,i});
			st[i].insert(ew);
		}
		//cout<<"============================";
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		bool bbdn=0;
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			if(st[i].find(y)!=st[i].end()&&st[i].find(x)!=st[i].end()){
				int nq1,nq2;
				bbdn=1;
				for(auto c:w[x]) if(c.xian==i) {nq1=c.t;break;}
				for(auto c:w[y]) if(c.xian==i) {nq2=c.t;break;}
				ans=max(za[x]+za[y]+nq1+nq2,ans);
			}
		}
		if(bbdn){
			cout<<ans<<endl;
			continue;
		}
//		for()
		
	}
	
	return 0;
} 
