#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N][N];
int c,n,m,d,q,k;
int w[N],turn[N][N]={0};
vector<int> ji[N],line[N];
int ans1=0;
void dfs(int x,int y,int ans){
	if(x!=y){
		for(int i=1;i<=sizeof(turn[x]);i++){
			if(turn[x][i]>0){
				dfs(i,y,ans+turn[x][i]);
			}
		}
	}
	else if(x==y){
		ans1=max(ans1,ans);
		return;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			int cc,dd;
			cin>>cc>>dd; 
			line[i].push_back(cc);
			a[cc][i]=dd;
			a[i][cc]=dd;
			ji[cc].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(ji[i].size()>1){
			for(int j=1;j<=ji[i].size();j++){
				for(int k=1;k<=ji[i].size();k++){
				if(turn[j][k]==0){
					turn[j][k]=a[i][j]+a[k][i];
					turn[k][j]=a[i][j]+a[k][i];
				}
			}
			}
			
		}
	}
	while(k--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=ji[x].size();i++){
			for(int j=1;j<=ji[y].size();j++){
				dfs(i,j,0);
			}
		}
		cout<<ans1+w[x]+w[y]<<'\n';
	}
	return 0;
}

