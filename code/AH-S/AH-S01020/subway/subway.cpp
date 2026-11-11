#include<bits/stdc++.h>
using namespace std;
int c     ,        n,      m,                      d,        q,                  w[50001]={};
//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,出行计划数，每个地铁站的地铁口走到站厅需要的时间
int k[501]               ,a                             ,t;
//  第 i 条线路经过的地铁站数,a表示第 i 条线路经过的第 j 个地铁站,t表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
struct sub{
	short next[501];//next[i] 表示连接的i号线的站台的下一个站台的站厅编号，=0则后面连接着滚木
	short last[501];//last[i] 表示连接的i号线的站台的上一个站台的站厅编号，=0则后面连接着滚木
	short time[501];//time[i] 表示连接的i号线的站台到本站厅的时间,=0则后面连接着滚木
}s[500001];//s[i]代表第i个站厅,0号代表滚木站厅
short bfs(int x,int y){
	bool f[32767][501]={};
	short sum[32767][501]={};
	short q[500001]={};
	int head=1,tail=0;
	q[1]=x;
	for(int i=1;i<=n;i++){
		f[0][i]=1;
		f[x][i]=1;
		sum[x][i]=s[x].time[i];
	}
	short add;
	while(head>tail){
		tail++;
		for(short i=1;i<=n;i++){
			if(s[q[tail]].time[i]!=0){
				if(!f[s[q[tail]].last[i]][i]){
					if(sum[q[tail]][i]!=0){
						add=s[s[q[tail]].last[i]].time[i]+s[q[tail]].time[i];
						sum[q[tail]][i]=min(add,sum[q[tail]][i]);
					}
					else{
						sum[q[tail]][i]=s[s[q[tail]].last[i]].time[i]+s[q[tail]].time[i];
					}
					q[++head]=s[q[tail]].last[i];
					f[s[q[tail]].last[i]][i]=1;
				}
				if(!f[s[q[tail]].next[i]][i]){
					if(sum[q[tail]][i]!=0){
						add=s[s[q[tail]].next[i]].time[i]+s[q[tail]].time[i];
						sum[q[tail]][i]=min(add,sum[q[tail]][i]);
					}
					else{
						sum[q[tail]][i]=s[s[q[tail]].next[i]].time[i]+s[q[tail]].time[i];
					}
					q[++head]=s[q[tail]].next[i];
					f[s[q[tail]].next[i]][i]=1;
				}
			}
		}
	}
	short ans=32767;
	for(int i=1;i<=n;i++){
		if(sum[y][i])
		ans=min(ans,sum[y][i]);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[m];
	}
	int a1=0;//标记前一个站厅的编号
	for(int i=1;i<=n;i++){
		a1=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			s[a].time[i]=t;
			s[a1].next[i]=a;
			s[a].last[i]=a1;
//			cout<<"i="<<i<<" j="<<j<<" a1="<<a1<<"\n";
			a1=a;
		}
	}
/*	
	for(int i=1;i<=m;i++)
	{
		cout<<"这是"<<i<<"号站厅：其连接着";
		for(int j=1;j<=500;j++)
		{
			if(s[i].time[j]!=0)
			{
				cout<<j<<"号线的站台，到其时间为"<<s[i].time[j]<<"我的上一个站台是连接着"<<s[i].last[j]<<"号站厅的站台"<<"我的下一个站台是连接着"<<s[i].next[j]<<"号站厅的站台";
			}
		}
		cout<<endl;
	}
*/
	int x[100001]={},y[100001]={};
	//,起点和终点所在的地铁站编号
	short ans=32767;
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		for(int j=1;j<=n;j++){
			if(s[x[i]].time[j]!=0&&s[y[i]].time[j]!=0)
				ans=s[x[i]].time[j]+s[y[i]].time[j];
		}
		cout<<w[x[i]]+w[y[i]]+ans<<endl;
	}
	return 0;
}
