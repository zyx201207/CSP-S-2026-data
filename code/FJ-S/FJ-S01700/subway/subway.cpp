#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
ll w[M],minn=-1;
struct node{
	int id,num;
};
vector<int> a[505];
vector<ll> t[505];
vector<pair<int,int> > id[M];
void dfs(int now,int cnt,int aim,ll ans){
	//cout<<now<<" ";
	if(now==aim){
		if(minn==-1||ans<minn) minn=ans;
		return;
	}
	for(int i=0;i<(int)id[now].size();i++){
		int cen=id[now][i].first;
		if(cnt==cen) continue;
		
		for(int j=id[now][i].second+1;j<(int)a[cen].size();j++)
			dfs(a[cen][j],cen,aim,ans+t[cen][j]+t[cen][id[now][i].second]);
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int aa;ll tt;
			scanf("%d%lld",&aa,&tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
			id[aa].push_back(make_pair(i,(int)a[i].size()-1) );
		}
	}
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		minn=-1;
		dfs(x,0,y,0);
		//cout<<w[x]<<" "<<w[y]<<" "<<id[x].size()<<" ";
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}
