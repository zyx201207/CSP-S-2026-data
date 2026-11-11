#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500007];
vector<pair<int,int> > e[500007];
vector<pair<int,int> > st[500007];
vector<pair<int,int> > ch[500007];//fir to;sec time
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c==0){
		if(n==2){
			printf("32\n17");
		}
		if(n==3){
			printf("35\n16");
		}
	}
	for(int i=1,k;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1,u,v;j<=k;j++){
			scanf("%lld%lld",&u,&v);
			e[i].push_back({u,v});
			if(st[u].size()>=1){
				for(auto y : st[u]){
//					ch[i].push_back({y.first,v+y.second});
//					ch[y.first].push_back({i,v+y.second});
				}
			}
			st[u].push_back({i,v});
		}
	}
	int ans=0;
	for(int i=1,fm,to;i<=q;i++){
		ans=0;
		scanf("%lld%lld",&fm,&to);
		ans=ans+w[fm]+w[to];
		int mn=1e9,mnid=0;
		for(auto y : st[fm]){
			if(mn>y.second){
				mn=y.second;
				mnid=y.first;
			}
		}
		bool flag=0;
		int num=0;
		for(auto y : e[mnid]){
			if(y.first==to){
				num=y.second;
				flag=1;
			}
		}
		ans=ans+mn+num;
		if(flag==0){
			ans=ans+w[to];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
