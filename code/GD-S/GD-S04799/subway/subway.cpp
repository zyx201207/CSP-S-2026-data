#include<bits/stdc++.h>
using namespace std;
int w[5001];int t[51][5001];
struct node{
	int xx=1;
	int y[21];
	int z[21];
}k[5001];
long long bfs(int s,int e){
	if(s==e) return 0;
	long long ans=bfs(k[s].y[1],e)+t[k[s].z[1]][s]+t[k[k[s].y[1]].z[1]][k[s].y[1]];
	for(int i=2;i<k[s].xx;i++) ans=min(ans,bfs(k[s].y[i],e)+t[k[s].z[i]][s]+t[k[k[s].y[i]].z[i]][k[s].y[i]]);
	return ans;
}
int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	int c,n,m,d,q;
	fin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) fin>>w[i];
	for(int i=1;i<=n;i++){
		int kk;fin>>kk;int a[kk+1];
		for(int j=1;j<=kk;j++){
			fin>>a[j];
			for(int x=1;x<j;x++){
				k[j].y[k[j].xx]=a[x];
				k[j].z[k[j].xx]=i;
				k[a[x]].y[k[a[x]].xx]=j;
				k[a[x]].z[k[a[x]].xx]=i;
				k[j].xx++;k[a[x]].xx++;
			}
			fin>>t[i][j];
			
		}
	}
	while(q>0){q--;
	    int x,y;fin>>x>>y;
	    fout<<bfs(x,y)+w[x]+w[y];
	}
	fin.close();
	fout.close();
}
