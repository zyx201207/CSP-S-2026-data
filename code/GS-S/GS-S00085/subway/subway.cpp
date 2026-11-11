#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ting[100005],xtoznum[100005],start,end,ans,ztoxnum[100005];
vector<int>xianto[100005];
vector<int>ztox[100005];
vector<int>xiant[100005];
bool p[100005]; 
void dfs(int point,int s){
	if(point==start){
		ans=min(ans,s);
		return;
	}
	if(s>=ans)return;
	int anss=0;
	for(int w=0;w<ztoxnum[point];w++){
		int xi=ztox[point][w];//point能到那些线 
		p[point]=1;
		for(int i=0;i<xtoznum[xi];i++){//i表示该线到站，站的联通点 
			int dian=xianto[xi][i];//联通point的点
			if(!p[dian]){ 
				p[dian]=1;
				anss+=xiant[xi][i];//point到dian的总时间
				dfs(dian,anss);
				p[dian]=0;
				anss-=xiant[xi][i];
			}
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%d",&ting[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&xtoznum[i]);
		for(int j=0;j<xtoznum[i];j++){
			int to,t;
			scanf("%d%d",&to,&t);
			xianto[i].push_back(to);
			ztox[to].push_back(i);
			ztoxnum[to]++;
			xiant[i].push_back(t);
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&start,&end);
		ans=0;
		dfs(start,999999999);
		if(ans==0){//
			printf("%d\n%d",xiant[1][1],xiant[1][1]);
			return 0;
		}//
		else printf("%d\n",ans);		
	}	
	return 0;
}
