#include <bits/stdc++.h>
using namespace std;
int n;
bool way[n][n];
//int bfs(int s,int x,int y){
//	
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	memset(t,0,sizeof(t));
	int t;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			vector<int>a;
			int sta;
			cin>>sta>>t;
			for(int k=0;k<a.size();k++){
				way[sta][a[k]]==1;
				way[a[k]][sta]==1;
			}
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<(x+y)/2*t+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}		
