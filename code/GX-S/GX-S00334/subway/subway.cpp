#include<bits/stdc++.h>
using namespace std;
long long l,n,m,d,q;
long long a[1000001];
struct node{
	long long v,w;
};
long long zuiyoujie[1000001];
long long b[1000001],c[1000001];
vector<node>mp[100001];
void spfa(long long u,long long v,long long step){
	if(zuiyoujie[u]<step) return ;
	if(u==v){
		zuiyoujie[v]=step;
		return ;
	}
	for(auto tmp:mp[u]){
		long long v1=tmp.v,w1=tmp.w;
		if(zuiyoujie[v1]<step+w1) continue;
		zuiyoujie[v1]=step+w1;
		spfa(v1,v,step+w1);
	}
}
long long mx;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>l>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>a[i];
	for(long long v=1;v<=n;v++){
		long long k;
		cin>>k;
		
		for(long long j=1;j<=k;j++){
			cin>>b[j]>>c[j];
		}
		for(long long j=1;j<=k;j++){
			for(long long o=j+1;o<=k;o++){
				mp[b[j]].push_back({b[o],c[j]+c[o]});
				
				mp[b[o]].push_back({b[j],c[j]+c[o]});
			}
		}
	}
	/*for(long long i=1;i<=m;i++){
		for(auto tmp:mp[i]){
			cout<<tmp.v<<" ";
		}
		cout<<endl;
	}*/
	for(long long i=1;i<=q;i++){
		long long u,v;
		cin>>u>>v;
		for(int j=1;j<=1000000;j++) zuiyoujie[j]=10000000000000;
		spfa(u,v,0);
		cout<<zuiyoujie[v]+a[v]+a[u]<<"\n";
	}
	return 0;
}
