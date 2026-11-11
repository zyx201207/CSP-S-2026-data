#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+10;
ll c,n,m,d,q,w[N],t[510][N],ans,u,v,s[510][510];
vector<int> e[N];
vector<int> f[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	memset(s,0x3f,sizeof(s));
	for(ll i=1;i<=m;i++)
	    cin>>w[i];
	for(ll i=1,k;i<=n;i++){
		s[i][i]=0;
		cin>>k;
		for(ll j=1,a,b;j<=k;j++){
			cin>>a>>b;
			t[i][a]=b;
			e[i].push_back(a);
			f[a].push_back(i);
		}
		for(ll j=1;j<i;j++)
		    for(ll k:e[j])
		        if(t[i][k])
		            s[i][j]=s[j][i]=min(s[i][j],t[i][k]+t[j][k]);
	}
	for(ll k=1;k<=n;k++)
	    for(ll i=1;i<=n;i++)
	        for(ll j=1;j<=n;j++)
	            if(k!=i&&k!=j&&i!=j&&s[i][k]<1e17&&s[k][j]<1e17)
	                s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
	while(q--){
		cin>>u>>v;
		ans=1e18;
		for(ll i:f[u])
			for(ll j:f[v])
			    ans=min(ans,t[i][u]+s[i][j]+t[j][v]);
		cout<<w[u]+ans+w[v]<<endl;
	}
	return 0;
} 
