#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int w[maxn];
struct qs{
	int start,end;
}Qs[maxn];
struct node{
	int a,t;
}Node[maxn];
int k[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>Node[i].a>>Node[i].t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>Qs[i].start>>Qs[i].end;
		if(n==1){
			int mi=1e9;
			for(int i=1;i<=k[1];i++){
				if(Node[i].a==Qs[i].end){
					mi=min(mi,Node[i].t+w[Qs[i].start]);
				}
			}
			cout<<mi;
			return 0;
		}
		else{
			int mi=1e9;
			for(int i=1;i<=k[n];i++){
				if(Node[i].a==Gs.end){
					mi=min(mi+Node[i].t+w[Qs[i].start]);
				}
			}
			cout<<mi<<endl;
		}
	}
	return 0;
}
