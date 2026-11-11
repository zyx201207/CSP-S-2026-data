//GZ-S00258 ³Â±òˆ 
#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,st,en;
bool vis[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	if(c==0) c=1;
	while(c--){
		cin>>m>>n>>d>>q;
		vector<int> a[26];
		vector<int> t[26];
		int w[500010],k[500010];
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int asd,asdf;
				cin>>asd>>asdf;
				a[i].push_back(asd);
				t[i].push_back(asdf);
			}
		}
		cin>>st>>en;
		int ans=0;
		ans+=w[st]+w[en];
		for(auto e:)
	}
	return 0;
} 
