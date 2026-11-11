#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int i,j,k;
int a[5005];
struct node{
	int t,len;
};
vector<node>v1[5005],v2[5005];
int dist[5005],dtt[5005][5005],fl[5005],ff[5005][5005];
int bfs(int dt){
	memset(dist,0x3f3f3f,sizeof(dist));
	queue<int>q;
	q.push(dt);
	dist[dt]=0;
	fl[dt]=1;
	while(q.size()){
		int f=q.front();
		q.pop();
		//fl[f]=0;
		for(int i=0;i<v1[f].size();i++){
			int nd=v1[f][i].t;	
			//if(fl[nd]==0){
			if(dist[f]+v1[f][i].len<dist[nd]){
				dist[nd]=dist[f]+v1[f][i].len;
				dtt[dt][nd]=dist[nd];
				ff[dt][nd]=1;
				q.push(nd);
			}	
		}
	}
	return 2;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	//cout<<n<<"\n\n\n\n\n\n";
	//(ff,0,sizeof(ff));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//cout<<i;
	}
	int aline[505][3];
	for(i=1;i<=m;i++){
		int k1;
		cin>>k1;
		int ct[505][2];
		for(j=1;j<=k1;j++){
			scanf("%d%d",&ct[j][0],&ct[j][1]);
		}
		for(j=1;j<=k1;j++){
			for(k=1;k<=k1;k++){
				if(j!=k){
					v1[ct[j][0]].push_back({ct[k][0],ct[j][1]+ct[k][1]});
				}
			}
		}
		//for(j=1;j<=n;j++){
			//printf("%d:",j);
			//for(k=0;k<v1[j].size();k++){
			//	cout<<v1[j][k].t<<" "<<v1[j][k].len<<"    ";
			//}
			//cout<<endl;
		//}
	}
	while(q--){
		int aa,bb;
		cin>>aa>>bb;
		if(ff[aa][bb]==0) bfs(aa);
		printf("%d\n",dist[bb]+a[aa]+a[bb]);
	}
	return 0;
}
/* 
0 2 5 0 2
4 1 9 2 5
3   1 5 2 7 4 6
3   2 3 3 4 5 7
1 3
1 2
*  0 3 7 20 2 8 3 6 1 7 2 9 3 1 4 2 5 5 100 3 2 6 3 1 7 2 4 3 2 5 100 4 6 6 7 1 6 2 3
*/
