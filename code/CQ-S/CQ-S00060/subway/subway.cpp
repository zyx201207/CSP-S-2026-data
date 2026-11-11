#include<bits/stdc++.h>
using namespace std;

const int M=50010;
//c=测试点编号(?); n=地铁线路数; m=地铁站数; d=每个地铁站最多被几条线路经过; q=出行计划数 
int c,n,m,d,q;
//w[i]=第i个地铁站的地铁口走到站厅需要的时间 
int w[M];
//a[i]=某线路经过的第i个地铁站
int a[M][M];
//t[i]=第i个地铁站站厅走到该线路的站台需要的时间
int t[M][M];
//x=该出行计划的起点地铁站编号; y=该出行计划的终点地铁站编号
long long x,y;
//k[i]=第i条线路经过的地铁站数
long long k[M];

int main(){
	//规定输入输出
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//输入操作（出行计划相关变量不用统一输入储存）
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++)
			cin>>a[i][j]>>t[i][j];
	} 
	//设置临时参量
	int now;
	long long total_time=9e25+5;
	long long t=0;
	 
	//将每一种出行计划统一进行"输入+处理+输出"的复合操作 
	for(int k=1;k<=q;k++){
		cin>>x>>y;//输入每一种计划
		now=x;
		t=0;//初始化计算变量 
		//先找到当前位置有的路线，枚举 
		long long ki=0;
		while(now!=y){
			for(int i=0;i<n;i++){
				ki=k[i];
				for(int j=0;j<ki;j++){
					if(a[i][j]==now){
						t+=t[i][j];
						now=a[i][j+1];
				    }
				    //cout<<"t = "<<t<<endl;
				    //cout<<"now = "<<now<<endl;
				}
			//cout<<"t = "<<t<<endl;
			//cout<<"now = "<<now<<endl;
			if(t<total_time) total_time=t;
			}
		}
		//cout<<"t = "<<t<<endl;
		//cout<<"now = "<<now<<endl;
		
	}
	cout<<total_time<<endl;
	
	return 0;
}
