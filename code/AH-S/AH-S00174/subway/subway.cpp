#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node{
	int idx,val;
};
int w[500005];
vector<node> tim[500005];
int cst[505][505]={};
int crs[500005];
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/
inline int min(int x,int y){
	return x>y?y:x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(cst,0x3f3f3f3f,sizeof(cst));
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		//cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
//			cin>>a>>t;
			scanf("%d%d",&a,&t);
//			tim[i][a]=t;
			tim[a].push_back({i,t});
			crs[a]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(crs[i]!=1){
			int len1=tim[i].size();
			for(int j=0;j<len1;j++){
				for(int l=j+1;l<len1;l++){
					int idx1=tim[i][j].idx,idx2=tim[i][l].idx;
					cst[idx1][idx2]=min(cst[idx1][idx2],tim[i][j].val+tim[i][l].val);
					cst[idx2][idx1]=min(cst[idx2][idx1],tim[i][j].val+tim[i][l].val);
				}
			}
		}
	}
	/*
	 floyd??? 
	 甚至时间大部分花在建图上
	*/
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)cst[i][j]=0;
				else cst[i][j]=min(cst[i][j],cst[i][k]+cst[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1919810;
	//	int ss[505]={};
		for(int j=0;j<tim[x].size();j++){
			for(int k=0;k<tim[y].size();k++){
				ans=min(ans,cst[tim[x][j].idx][tim[y][k].idx]+tim[x][j].val+tim[y][k].val);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
