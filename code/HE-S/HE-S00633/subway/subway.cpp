#include <iostream>
#include <iomanip>
using namespace std;

int c,n,m,d,q;
int w[500001];
int mp[1001][1001];
int t;

void dfs(int x,int y,int t){
	for(int i=1;i<=m;i++){
		if(mp[x][i]!=0 && i==y){
			t+=mp[x][i]+mp[i][x]+w[i];
		}
		else if(mp[x][i]!=0){
			t+=mp[x][i]+mp[i][x];
			dfs(i,y,t);
		}
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			mp[a1][a2]=t1;
			mp[a2][a1]=t2;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		t=w[x];
		if(mp[x][y]!=0){
			cout<<w[x]+mp[x][y]+mp[y][x]+w[y]<<endl;
		}
		else{
			dfs(x,y,t);
			cout<<t<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
