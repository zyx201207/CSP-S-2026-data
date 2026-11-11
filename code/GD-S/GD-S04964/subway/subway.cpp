#include<cstdio>
#include<iostream>
#include<vector>
#define ll long long 
using namespace std;
const int N=501;
const int M=2e4+10; 
const int D=31;
const ll INF=0x3f3f3f3f3f; 
ll c,n,m,d,q,u,v;
ll w[M],a[N][M],t[N][M],ans=INF;
struct node{
	int line,cd;
};
node pt[M][N];
bool vis1[M],vis2[N];
void dfs(int now,ll time,int line,int cd,ll step){
	//cout<<now<<" "<<time<<" "<<line<<endl;
	if(now==v){
		if(line==0) ans=min(ans,time);
		else ans=min(ans,time+t[line][cd]);
		return;
	}
	if(line==0){
		for(int i=1;i<=pt[now][0].line;i++){
			if(!vis2[pt[now][i].line]){
				vis2[pt[now][i].line]=true;
				//cout<<pt[now][i].line<<"***\n";
				dfs(now,time+t[pt[now][i].line][pt[now][i].cd],pt[now][i].line,pt[now][i].cd,step+1);
				vis2[pt[now][i].line]=false;
			}
		}
	}
	else{
		if(cd<a[line][0]&&!vis1[a[line][cd+1]]){
			vis1[a[line][cd+1]]=true;
			dfs(a[line][cd+1],time,line,cd+1,step+1);
			vis1[a[line][cd+1]]=false;
		}
		if(cd>1&&!vis1[a[line][cd-1]]){
			vis1[a[line][cd-1]]=true;
			dfs(a[line][cd-1],time,line,cd-1,step+1);
			vis1[a[line][cd-1]]=false;
		}
		dfs(now,time+t[line][cd],0,0,step+1);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>t[i][j];
			pt[a[i][j]][++pt[a[i][j]][0].line]=node{i,j};
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ans=INF;
		//cout<<"************"<<endl;
		vis1[u]=true;
		dfs(u,0,0,0,0);
		for(int j=1;j<=n;j++) vis2[j]=false;
		for(int j=1;j<=m;j++) vis1[j]=false;
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}
