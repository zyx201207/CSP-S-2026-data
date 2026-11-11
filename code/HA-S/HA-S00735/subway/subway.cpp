#include<bits/stdc++.h>
using namespace std;
int m,n,q,c,d;
int k[500005];
int line[505][500005];
int t[505][500005];
int w[500005];
int plan[100005][2];
int ans;
int num;
void a(int x,int y){
	ans=w[x]+w[y];
	
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>line[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=k[i];j++){
			if(line[i][j]==line[i+1][j]){
				num=line[i][j];
			}
		}
	}
	
	for(int r=1;r<=q;r++){
		cin>>plan[r][1]>>plan[r][2];
	}
	
	for(int i=1;i<=q;i++){
		int ans=0;
		a(plan[i][1],plan[i][2]);
	}
	
	return 0;
}
