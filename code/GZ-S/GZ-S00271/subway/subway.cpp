//GZ-S00271 姓名：周昊杨 学校：贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int w[N],s,e,t[N],n,c,m,d,q,len[505],v,w1;


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			cin>>v>>w1;
			w[v]=w1;
		}

	}

	while(q--){
		cin>>s>>e;
		int ans=t[s]+t[e];
		for(int i=1;i<=n;i++){
			ans+=w[i];
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

