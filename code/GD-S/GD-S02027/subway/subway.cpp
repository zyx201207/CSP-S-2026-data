#include<bits/stdc++.h>
using namespace std;
const int N=505;
int b[N][2*N];
int f[N][2*N];
int k[N];
int d[N][N];
int w[N];
int s[N];
int minn=1e9;
void stu(int x,int y,int cnt){
	for(int i=1;i<=s[x];i++){
		int p=d[x][i];
		for(int j=1;j<=k[p];j++){
			int o=b[p][j];
			if(o==y){
				minn=min(cnt+w[y],minn);
			}
			else{
				stu(o,y,cnt+f[p][1]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>b[i][j]>>f[i][j];
			int p=b[i][j];
			d[p][++s[b[i][j]]]=i;
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		stu(x,y,0);
		cout<<minn<<"\n";
	} 
	return 0;
}
