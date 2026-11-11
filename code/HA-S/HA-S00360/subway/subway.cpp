#include<bits/stdc++.h>
using namespace std;
int tot=0,sum=0,vis[500005]={},lj[505][505]={},x,y,w[500005],c,n,m,d,q,a[505][505],k,t[505][505];
int dfs(int name,int xl){
//	if(name==y){
//		sum+=t[xl][y];
//		return sum;
//	}
	for(int i=1;i<=m;i++){//地铁站 
		//if(name==i) continue;
		for(int j=1;j<=n;j++){//线路 
			if(lj[j][i]==1&&lj[j][y]==1){
				sum+=t[j][y]+t[xl][i];
				return sum;
			}
			if(j==xl) continue;
			if(lj[xl][i]==1&&lj[xl][name]==1&&lj[j][i]==1&&vis[i]==0){
				sum+=t[xl][i]+t[j][i];
				vis[i]=1;
				dfs(i,j);
				sum-=t[xl][i]+t[j][i];
				vis[i]=0;
			}
		}
	} 
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]); //地铁站
	}
	
	for(int i=1;i<=n;i++){//地铁线路
		scanf("%d",&k);
		for(int j=1;j<=k;j++){ 
			scanf("%d%d",&a[i][j],&t[i][j]);
			lj[i][a[i][j]]=1;//第i条地铁线路通过第a[i][j]个站 
		}
	}
	//cout<<0;
	for(int i=1;i<=q;i++){
		//cout<<1;
		tot=INT_MAX;
		scanf("%d%d",&x,&y);
		//tot+=(w[x]+w[y]);
		sum=0;
		int flag=0;
		for(int j=1;j<=n;j++){
			if(lj[j][x]==1&&lj[j][y]==1){
				cout<<w[x]+w[y]+t[j][x]+t[j][y];
				flag=1; 
				break;
			}else if(lj[j][x]){
				sum=t[j][x];
				tot=min(tot,dfs(x,j));
			}
			//int flag=0,o=tot;
			
			//if(o!=tot) flag=1;
		}
		//if(flag=0)cout<<w[x]+w[y];
		if(flag==0)
		cout<<tot+w[x]+w[y]<<endl;
	}
	
	return 0;
}

