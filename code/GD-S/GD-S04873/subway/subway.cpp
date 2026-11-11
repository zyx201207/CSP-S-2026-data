#include<bits/stdc++.h>
using namespace std;
int T,n,m,d,p;
int from,to;int sum=0;
struct node{
	int w;
	int chg[505];
} sta [500005];
struct far{
	int id;
	int l;
};
bool vis[500005];
vector<far> sub[500005];
stack <int> Q;

int ans=0x3f3f3f3f;

void dfs(){//没招了打深搜吧 
	
	if(Q.empty()){
		return;
	}
	int now=Q.top();
	if(now==to){
		ans=min(ans,sum);
		//cout<<"抵达"<<ans<<endl; 
	}
	Q.pop();
	for(int i=0;i<sub[now].size();i++){
		if(vis[sub[now][i].id]==0){
			vis[sub[now][i].id]=1;
			Q.push(sub[now][i].id);
			//cout<<"当前"<<now<<"去往"<<sub[now][i].id<<' ';
			sum+=sub[now][i].l;
			//cout<<sum<<endl;
			
			dfs();
			//cout<<endl;
			sum-=sub[now][i].l;
			vis[sub[now][i].id]=0;
		}
	}
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>T>>n>>m>>d>>p;
	if(T==0){
		T=1;
	}
	while(T--){
		for(int i=1;i<=m;i++){
			cin>>sta[i].w;//每个点的出站消耗 
		}
		int c;
		for(int i=1;i<=n;i++){
			cin>>c;//路线i经过几个站点 
			int ki,kp;//经过站点与其转乘权值 
			for(int j=1;j<=c;j++){
				cin>>ki>>kp;//把每条地铁线路当作一个点来看 ，直接统计点之间的距离 
				sta[ki].chg[i]=kp;//输入数值 
				//cout<<"   把"<<ki<<"连接到线路"<<i<<"上,长度"<<kp<<endl;
			}
		}for(int j=1;j<=m;j++){//开始统计距离 并存入邻接表 
			for(int k=1;k<=m;k++){//判断点2 
				if(j==k)continue;
				for(int l=1;l<=n;l++){//线路 
					if(sta[j].chg[l]==0){
						//if(l==3)cout<<"  33333  "<<endl;
						break;//没有这条线路，下一次循环 
					}
					if(sta[k].chg[l]!=0){//遍历到的两点共同通往某条线路 
						//单向赋值防止重复
						far aa;
						aa.id=k;aa.l=sta[j].chg[l]+sta[k].chg[l];
						sub[j].push_back(aa); 
						//cout<<j<<' '<<k<<' '<<"长度"<<aa.l<<endl;
					}
				}
				
			} 
		}//赋值完毕 
		
		int nowid,nowt;
		for(int i=1;i<=p;i++){
			sum=0;
			cin>>from>>to;
			nowid=from;
			Q.push(from);
			dfs();
			ans+=sta[from].w+sta[to].w;
			cout<<ans;
			ans=0x3f3f3f3f;
		}
	}
	return 0;
}
