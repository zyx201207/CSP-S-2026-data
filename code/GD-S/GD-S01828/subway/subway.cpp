#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,c,n,m,k,ans,o,p,a[515414],v[5145][5145],x[515415],y[515451],l,r,f[5154514]; 
struct awp{int x,y;};
vector <awp> s[515414];
struct akm{
	int x,y;
	bool friend operator < (akm o,akm p){return o.y>p.y;};
};
priority_queue <akm> q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>k>>t;
	for(int i=1;i<=m;i++) cin>>a[i];
	memset(v,0x3f3f,sizeof(v));
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>x[j]>>y[j];
			for(int o=1;o<j;o++){
				if(y[j]+y[o]<v[x[j]][x[o]]){
					s[x[j]].push_back({x[o],y[j]+y[o]});
					s[x[o]].push_back({x[j],y[j]+y[o]});
				}
				v[x[j]][x[o]]=v[x[o]][x[j]]=min(v[x[o]][x[j]],y[j]+y[o]); 
			}
		}
	}
	if(c==20||c==21||c==22||c==23){
		while(t--){
			cin>>o>>p;
			memset(f,0x3f3f,sizeof(f));
			while(q.size()) q.pop();
			q.push({o,0}),f[o]=0;
			while(q.size()){
				l=q.top().x,r=q.top().y,q.pop();
				if(p==l){
					cout<<r+a[o]+a[p]<<endl;
					break;
				}
				for(auto u:s[l]){
					if(f[u.x]>r+u.y){
						f[u.x]=r+u.y;
						q.push({u.x,r+u.y});
					}
				}
			}
		}
		return 0;
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j||i==l||j==l) continue;
				v[i][j]=min(v[i][j],v[i][l]+v[l][j]);
			}
		}
	}
	while(t--){
		cin>>l>>r;
		cout<<v[l][r]+a[l]+a[r]<<endl;
	}
}
