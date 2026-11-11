#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50000];
struct node{
	int father;
	int time;
}line[500];
vector<vector<int>> mapp;

int tt[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			int last=a;
			cin>>a>>t;
			for(int k=1;k<=m;k++){
				tt[a+n*k][a+n*i]=t+w[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				tt[i][j]=min(tt[i][j],tt[i][k]+tt[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		int ans=0xf3f3f3f3f;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				ans=min(tt[s][e],tt[s+n*i][e+n*j]);
			}
			
		}
		
		cout<<ans;
	}
	//cout<<ans;
	return 0;
}
