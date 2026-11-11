#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,ans;
struct sta{
	long long w;
	long long l[30],t[30];
};
sta st[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>st[i].w;
	for(int i=1;i<=n;++i){
		int k; cin>>k;
		while(k--){
			long long p;
			cin>>p>>st[p].t[i];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		ans=st[x].w+st[y].w+20;
		cout<<ans;
	}
	return 0;
} 
