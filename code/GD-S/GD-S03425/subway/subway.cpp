#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,aa,bb,cc,dd,ee,ff,to[1200005],nxt[1200005],head[1100005],val[1200005],cnt,u[500005],bcnt,dist[1100005],ans[100005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
vector<tuple<int,int,int> >questions;
void add(int a,int b,int v){
	to[++cnt]=a;
	nxt[cnt]=head[b];
	head[b]=cnt;
	to[++cnt]=b;
	nxt[cnt]=head[a];
	head[a]=cnt;
	val[cnt-1]=val[cnt]=v;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	bcnt=m;
	for(int z=1;z<=m;z++){
		cin>>aa;
		u[z]=aa;
	}
	for(int z=1;z<=n;z++){
		cin>>aa;
		cin>>bb>>cc;
		int abcd=++bcnt;
		add(abcd,bb,cc);
		for(int y=2;y<=aa;y++){
			cin>>dd>>ee;
			add(abcd,++bcnt,0);
			add(bcnt,dd,ee);
		}
	}
	questions.push_back(make_tuple(0,0,0));
	for(int z=1;z<=q;z++){
		cin>>aa>>bb;
		if(aa>bb)swap(aa,bb);
		questions.push_back(make_tuple(aa,bb,z));
	}
	sort(questions.begin(),questions.end());
	for(int z=1;z<questions.size();z++){
		auto y=questions[z];
		if(get<0>(y)!=get<0>(questions[z-1])){
			memset(dist,0x7f,sizeof dist);
			dist[get<0>(y)]=0;
			pq.push({0,get<0>(y)});
			while(!pq.empty()){
				auto tt=pq.top();
				pq.pop();
				if(tt.first>dist[tt.second])continue;
				for(int x=head[tt.second];x;x=nxt[x]){
					if(tt.first+val[x]>=dist[to[x]])continue;
					dist[to[x]]=tt.first+val[x];
					pq.push({dist[to[x]],to[x]});
				}
			}
		}
		ans[get<2>(y)]=dist[get<1>(y)]+u[get<0>(y)]+u[get<1>(y)];
	}
	for(int z=1;z<=q;z++){
		cout<<ans[z]<<"\n";
	}
	return 0;
}
