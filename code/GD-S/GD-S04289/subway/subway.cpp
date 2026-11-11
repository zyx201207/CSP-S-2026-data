#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],a[505][500010],t[505][500010],ans=0,fn=0;
struct Station{
	vector<int> q;
    int num;
	int z;
}b[10010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j>1){
				b[a[i][j]].q.push_back(a[i][j-1]);
				b[a[i][j-1]].q.push_back(a[i][j]);
			}
			b[a[i][j]].num=i;
			b[a[i][j]].z=j;
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=w[x]+a[b[x].num][x]+a[b[y].num[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
