#include<bits/stdc++.h>
using namespace std;
struct Line{
	int l;
	int go[200007];
	int no[200007];
}line[500];
int lj[10005][10005];
int dist[200007];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	int a,b;
//	cin>>a>>b;
//	for(int i=1;i<=b;i++){
//		cout<<i<<endl;
//	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dist[i];
	}
	for(int i=1;i<=n;i++){
		cin>>line[i].l;
		for(int j=1;j<=line[i].l;j++){
			cin>>line[i].no[j]>>line[i].go[j];
		}
	}
	memset(lj,0x3f,sizeof(lj));
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<=n;k++){
				lj[i][j]=lj[j][i]=min(lj[i][j],line[k].no[i]+line[k].no[j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		cout<<lj[st][en]+dist[st]+dist[en]<<"\n";
	}
	return 0;
}
