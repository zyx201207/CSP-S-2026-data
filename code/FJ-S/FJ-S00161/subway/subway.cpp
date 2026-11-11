#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
long long c,n,m,d,q;
long long tmp[N][2],t[N],w[N],r[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			if(i==1){
				r[x]=1;
			}
			else{
				if(r[x]==1){
					r[x]=3;
				}
				else{
					r[x]=2;
				}
			}
			tmp[x][i]=y;
		}
	}
	long long minn=2e9;
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		if(r[a]==r[b]){
			cout<<w[a]+w[b]+tmp[a][r[a]]+tmp[b][r[a]]<<'\n';
		}
		else{
			long long minn=2e9;
			for(int j=1;j<=m;j++){
				if(r[j]==3){
					minn=min(minn,tmp[j][1]+tmp[j][2]);
				}
			}
			if(r[a]==3&&minn==tmp[a][1]+tmp[a][2]){
				cout<<w[a]+w[b]+tmp[a][r[b]]+tmp[b][r[b]]<<'\n';
			}
			if(r[b]==3&&minn==tmp[b][1]+tmp[b][2]){
				cout<<w[a]+w[b]+tmp[a][r[a]]+tmp[b][r[a]]<<'\n';
			}
			else{
				cout<<w[a]+w[b]+minn+tmp[a][r[a]]+tmp[b][r[b]]<<'\n';
			}
		}
	}
	return 0;
}
