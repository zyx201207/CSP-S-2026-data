#include<bits/stdc++.h>
using namespace std;
struct st{
	priority_queue<pair<int,int>> go;
};
struct sta{
	priority_queue<int> sub;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(1){
		int w[20050],a[505][2],k[505];st go[505];sta yes[20050];
		priority_queue <int> sub[505];
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			k[i]=x;
			for(int j=1;j<=x;j++){
				pair<int,int> aa;int aaf,aas;
				cin>>aaf>>aas;
				aa={aaf,-aas};
				go[i].go.push(aa);
				yes[aaf].sub.push(x);
			}
		}
		while(q--){
			long long ans=0;
			int x,y;
			cin>>x>>y;
			ans+=w[x];
			ans+=w[y];
			if(y>x){
				swap(x,y);
			}
			while(x!=y){
				priority_queue<pair<int,int>> pq1=go[yes[x].sub.top()].go;
				pair<int,int> pa=pq1.top();
				x=pa.first;
				ans-=pa.second;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}