#include<bits/stdc++.h>
using namespace std;
const int N=100001;
short c,n,d;
long long ti=0;
int m,q,k,sum=0;
int w[N];//口到站厅 
int s[N][21];//通向 
int dd1[N][21],pl[N],to[N];//到站口 
int main (){
	//queue<int> qu;
	//B:bfs搜索最短路径 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>s[i][j]>>dd1[i][j];
			s[i][j]--;
		}
		if(k<=2) sum++;
	}
	for(int i=0;i<q;i++){
		cin>>pl[i]>>to[i];
		pl[i]--;to[i]--;
	}
	int st;
	if(sum==n){
		for(int i=0;i<q;i++){
			for(int j=0;j<n;j++){
				if(s[j][0]==pl[i]||s[j][1]==pl[i]){
					st=j;
					break;//找起点 
				}
			}
			ti+=w[st];//下站厅 
			ti+=s[st][0]==st?dd1[st][0]:dd1[st][1];// 走到站口 
			while(!(s[st][0]==to[i]||s[st][1]==to[i])){
				ti+=s[st][0]!=st?dd1[st][0]:dd1[st][1];
				st=s[st][0]==st?s[st][1]:s[st][0];
				ti+=s[st][0]==st?dd1[st][0]:dd1[st][1];//换乘 
			}
			ti+=s[st][0]!=st?dd1[st][0]:dd1[st][1];
			st=s[st][0]==st?s[st][1]:s[st][0];
			ti+=w[st];//上地铁口 
			cout<<ti<<endl;
			ti=0;
		}
	}else{
		//solve();
	}
	return 0;
}
