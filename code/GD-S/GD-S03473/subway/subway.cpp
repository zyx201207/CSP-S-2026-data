#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],k[N],miti[N],x[N],y[N];
vector<int>a[N];
vector<int>t[N];
void dfs(int r){
	for(int i=1;i<=a[i].size();i++){
		
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)miti[i]=N;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ma,mb;
			cin>>ma>>mb;
			a[j].push_back(ma);
			t[j].push_back(mb);
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	//for(int i=1;i<=q;i++)cout<<rand()<<"\n";
	for(int i=1;i<=q;i++)dfs(i);
	return 0;
}

