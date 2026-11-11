#include<bits/stdc++.h>
using namespace std;
int n,m,d,q;
vector<int>w;//无关紧要的站台与门距离，答案最后加上就行了
vector<vector<int>>IN;
vector<vector<int>>OUT;
vector<vector<int>>Distance;
vector<vector<int>>MinDistance; 
int DP(int from,int to)//求节点from与to的最短距离 
{
	if(MinDistance=!INT_MAX)return MinDistance;
	for(i:OUT[from])
	{
		MinDistance[from][to]=min(Distance[from][to],Distance[from][i]+MinDistance(i,to));
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;//测试点编号 
	cin>>c;
	cin>>n>>m>>d>>q;//地铁线路数，地铁站数，最大线路容纳量，出行计划数
	//思路：化为带权无向图处理
	//节点数：m+n
	IN.resize(m+n+1,vector<int>());
	OUT.resize(m+n+1,vector<int>());//1-based
	Distance.resize(m+n+1,vector<int>(m+n+1,-1));
	MinDistance.resize(m+n+1,vector<int>(m+n+1,INT_MAX));
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		w.push_back(tmp);
	}//初始化第一行
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
    	for(int i=0;i<k;i++)
	    {
			int a,t;
			cin>>a>>t;
			//表示节点a+m与a之间有一个距离为t的边
			IN[a].push_back(a+m);
			IN[a+m].push_back(a);
			OUT[a].push_back(a+m);
			OUT[a+m].push_back(a);
			Distance[a][a+m]=t;
			Distance[a+m][a]=t;
		}
	}//初始化下面n行
	
	 for(int i=0;i<q;i++)
	 {
	 	int x,y;
	 	cin>>x>>y;
	 	cout<<DP(x,y);
	 }//多组数据 
	return 0;
}
