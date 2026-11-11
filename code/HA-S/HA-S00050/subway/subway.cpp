#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005];
struct node1{
	int a,t;
}w1[500005];
struct node2{
	int x,y;
}w2[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<=k[i];j++){
			cin>>w1[j].a>>w1[j].t;
		}
	}
	for(int i=0;i<q;i++){
		cin>>w2[i].x>>w2[i].y;
	}
	for(int i=0;i<q;i++){
		int ans=0;
		ans+=w[w2[i].x-1]+w1[i].t+w[w2[i].y-1]+w1[i].t;
		cout<<ans<<'\n';
	}
	return 0;
}
