#include<bits/stdc++.h>
using namespace std;
int ri(){
	int ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){}
	for(;isdigit(c);c=getchar())	ans=ans*10+(c^48);
	return ans;
}
struct edg{
	int to,next,m;//m:换乘需要的时间 
	int n;//该线路段属于哪一个线路 
}a[20010];
int head[510],cnt;
void add(int x,int y,int z,int n){
	cnt++;
	a[cnt].to=y,a[cnt].next=head[x],a[cnt].m=z;
	a[cnt].n=n;
	head[x]=cnt;
}
int b[10010];
int x[500010],y[50010];
bool vis[500010];
int ans[500010];
int m;
map<pair<int,int>,int> asdf;//?
int dij(int xx,int yy){
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	//pair<来时的距离,pair<点编号,边编号>> 
	q.push(make_pair(0,make_pair(xx,-1)));
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		int dis=now.first;
		
		auto se=now.second;
		vis[se.first]=1;
		//cout<<se.first<<endl;
		if(se.first==yy){
			int eee=asdf[{dis,se.first}];//?
			for(int j=head[se.first];j;j=a[j].next){
				if(a[j].to==eee){
					dis+=a[j].m;
					break;
				}
			}			
			for(int i=1;i<=m;i++)	cout<<ans[i]<<" ";
			return dis;//已找到 
		}
		for(int i=head[se.first];i;i=a[i].next){
			int _new=a[i].to;//候选目的地节点 
			if(vis[_new])	continue;
			int new_dis=dis;
			if(se.second!=a[i].n){
				//计算换乘时间
				new_dis+=a[i].m;
				int eee=asdf[{dis,se.first}];//?
				for(int j=head[se.first];j;j=a[j].next){
					if(a[j].to==eee){
						new_dis+=a[j].m;
						break;
					}
				}
			}
			else{/*同类不换乘*/} 
			if(new_dis>=ans[_new])	continue;//还不如上一次
			ans[_new]=new_dis;
			asdf[{new_dis,_new}]=se.first;
			q.push(make_pair(new_dis,make_pair(_new,a[i].n)));
		}
	}
	
}
void solve(){
	for(int i=1;i<=m;i++)	ans[i]=INT_MAX,vis[i]=0;
	int c_x=ri(),c_y=ri();
	 
	cout<<b[c_x]+dij(c_x,c_y)+b[c_y]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=ri(),n=ri();
	m=ri();
	int d=ri(),q=ri();
	for(int i=1;i<=m;i++)	b[i]=ri();
	for(int i=1;i<=n;i++){
		int k=ri();
		for(int j=1;j<=k;j++){
			x[j]=ri(),y[j]=ri();
			if(j>=2)	add(x[j-1],x[j],y[j-1],i);
		}
		for(int j=k;j>=1;j--){
			if(j<k)	add(x[j+1],x[j],y[j+1],i);
		}
	}
	while(q--)	solve();
	return 0;
}
/*
测试点： 
0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
*/

