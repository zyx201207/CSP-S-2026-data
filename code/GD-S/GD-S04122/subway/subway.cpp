#include <bits/stdc++.h>
using namespace std;
const int M=500010;
int c,n,m,d,q;
int sta[M];
int way[510][M];//每条地铁线路经过哪几个站 
int wayth[510];//每条地铁线路过几个站 
int son[M][30];//每个地铁站有经过哪几个地铁线路
int through[M];//每个站有多少个地铁经过 
int son2[M][30];//每个地铁站到各个经过的站台时长  
int ans=INT_MAX;
bool flag[M];
void find(int st,int ed,int wa){
	if(st==ed){
		ans=min(ans,wa+sta[ed]);
		return ;
	}
	//cout<<through[st]<<endl<<"-----------------------------"<<endl;
	for(int i=1;i<=through[st];i++){//i遍历经过st站的地铁线 
		for(int j=1;j<=wayth[son[st][i]];j++){
			if(!flag[way[i][j]]/* and through[way[i][j]]>1*/){
				flag[way[i][j]]=true;
				//cout<<st<<way[i][j]<<" "<<wa+son2[st][i]+son2[way[i][j]][i]<<endl;
				find(way[i][j],ed,wa+son2[st][i]+son2[way[i][j]][i]); 
				flag[way[i][j]]=false;
			}
		}
	}
	//if(through[st]==1) return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>sta[i];
	for(int i=1;i<=n;i++){
		cin>>wayth[i];
		for(int j=1;j<=wayth[i];j++){
			int a,t;cin>>a>>t;
			son2[a][++through[a]]=t;//a站到i铁道站台要t时长
			son[a][through[a]]=i;  
			way[i][j]=a;
		}	
	} 
	for(int i=1;i<=q;i++){
		memset(flag,false,sizeof flag);
		ans=INT_MAX;
		int st,ed;
		cin>>st>>ed;
		//flag[st]=true;
		find(st,ed,sta[st]);
		//cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
