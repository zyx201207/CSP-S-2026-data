#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=0x8f8f8f8f;
const int N=550;
const int M=3e5+10;
int st,endd;
int C,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[M],k[M],zxls[M];//zxls[i]表示第i站台有几条线路到达 
int cango[N][M],zxl[M][N];
int mapp[N][M];//mapp[i][j] 表示第i条线路到达j地铁站， 且第j地铁站站厅到达第i站台的时间   到不了就是0 

bool ish[M];
ll ans=MAXN;
void dfs(int now,int laxl,ll tolt){//当前在第now个站  ,上一条线路是laxl ,总用时长tolt 
	if(ish[now]) return;
	ish[now]=true;
	if(now == endd){
		ans=min(ans,tolt+mapp[laxl][now]);
		return;
	}
	if(tolt >= ans) return;
	for(int i=1;i<=zxls[now];i++)
	{
		int whxl=zxl[now][i];//哪条线路经过该站台 
		for(int j=1;j<=k[whxl];j++)
		{
			if(ish[cango[whxl][j]] == 0){
				if(laxl == whxl){
					dfs(cango[whxl][j] ,whxl,tolt);
				}
				else if(laxl == -1){
					dfs(cango[whxl][j] ,whxl,tolt+mapp[whxl][now]);
				}
				else{
					dfs(cango[whxl][j] ,whxl,tolt+mapp[laxl][now]+mapp[whxl][now]);
				}
			}
			
		}
	}
	ish[now]=false;
	return;
}
int ma[1005][1005];
struct node{
	int to,wei;
};
int zuidu(int s,int e){
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=m;k++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ma[i][j] > ma[i][k]+ma[k][j]) ma[i][j]=ma[i][k]+ma[k][j];
			}
		}
	}
	return ma[s][e];
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
//	cout<<ans<<endl;
	bool flag1=true;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2) flag1=false;
		int aa,tt;
		for(int j=1;j<=k[i];j++)
		{
			cin>>aa>>tt;
			mapp[i][aa]=tt;
			cango[i][j]=aa;
			zxls[aa]++,zxl[aa][zxls[aa]]=i; 
		}
	}
	if(flag1 && m>=400){
		
		for(int i=1;i<=n;i++)//建图 
		{
			if(k[i]>=2){
				int s1=cango[i][1],e1=cango[i][2];
				ma[s1][e1]=ma[e1][s1]=mapp[i][s1]+mapp[i][e1];
			}
		}
		while(q--)
		{
			cin>>st>>endd;
			cout<<zuidu(st,endd)<<endl;
		}
	}
	else{
		while(q--){
			cin>>st>>endd;
			for(int i=1;i<=m;i++) ish[i]=0;
			ans=MAXN;
			dfs(st,-1,w[st]+w[endd]);
			cout<<ans<<endl;
			
		}
	}
	
	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5                         地铁站口到站厅再到具体的线路站台  
3 1 5 2 7 4 6                    第几条线路到达哪个地铁站，以及从站台走到站厅 
3 2 3 3 4 5 7
1 3
1 2
*/
