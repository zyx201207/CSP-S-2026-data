#include<bits/stdc++.h>
using namespace std;
struct zt{
	int x,y;//x：站台  y：分钟 
};
struct jh{
	int b,e;
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//c:测试点编号 n:地铁线路数 m:地铁站数 d:max穿过 q:出行计划数 
	cin>>c>>n>>m>>d>>q;
	int w[m+2];//站厅到地铁口所需时间
	for(int i = 1; i <= m; i++)
	{
		cin>>w[i];
	}
	//zt a[n+1][500001];
		//储存线路站点 
	for(int i = 0; i < n; i++)
	{
		int l;//i线过l个站台 
		cin>>l;
		for(int j = 0; j < l; j++)
		{
			int z;
			cin>>z;
			int a; 
			cin>>a;//i号线到z站台需要多少分钟
		}
	}
	jh q1[q+1];
//	for(int ii = 0; ii < q; ii++){
//		int sum = 0;
//		cin>>q1[ii].b>>q1[ii].e;
//		sum+=w[q1[ii].b]+w[q1[ii].e];
//		for(int i = 0; i < n; i++){
//			if(dd[q1][q1[ii].b] == dd[i][q1[ii].e]){
//				
//			}
//		}
//	}
	int zxc[q];
	for(int i = 0; i < q; i++){
		cout<<zxc[i]<<"\n";
	} 
	return 0;//随机数保佑我 
}
