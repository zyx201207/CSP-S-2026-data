#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],t[500005],s,e,ans,MIN;
struct RP{
	int Ct,Te;
};
vector<RP> l[500005];
void dfs(long long st,long long bs,long long sj){
	if(sj>MIN){
		return ;
	}if(st==e){
		MIN=min(MIN,sj);
		return ;
	}if(bs>m){
		return ;
	}for(int i=0;i<l[st].size()-1;i++){
		dfs(l[st][i].Ct,bs+1,sj+l[st][i].Te+l[st][l[st].size()-1].Te);
	}return ;
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}for(int j=1;j<=k;j++){
			for(int K=j+1;K<=k;K++){
				l[a[j]].push_back({a[K],t[K]});
				l[a[K]].push_back({a[j],t[j]});
			}l[a[j]].push_back({a[j],t[j]});
		}
	}for(int i=1;i<=q;i++){
		MIN=2e18+7;
		cin>>s>>e;
		ans=w[s]+w[e];
		dfs(s,1,ans);
		cout<<MIN<<"\n";
	}return 0;
}//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//csp-s RP++
//求求了，给我我暴力12分吧
