#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010],k[500010],a[500010],t[500010];
struct sub{
	int t,w;
}s[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		fa[i]=i;
		cin>>s[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int a;
			cin>>a>>s[a].t;
		}
	}
	while(q--){
		int st,en;
		cin>>st>>en;
		long long mins=s[st].w+s[st].t+s[en].w+s[en].t;
		cout<<mins<<"\n";
	}
}