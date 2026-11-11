#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

int w[500005];

struct station{
	
	int k;
	
	int s1,t1,s2,t2;
	
};

station b[514]

struct plan{
	
	int x,y;
	
};

plan pl[500005];

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		
		cin>>w[i];
		
	}
	
	for(int i=1;i<=n;i++){
		
		cin>>b[i].k>>b[i].s1>>b[i].t1;
		
		if(b[i].k==2)cin>>b[i].s2>>b[i].t2;
		
	}
	
	for(int i=1;i<=q;i++){
		
		cin>>pl[i].x>>pl[i].y;
		
	}
	//这题真是牛大了 我这辈子没见过这么复杂的输入
	//还不能随便输出一些东西 我炸了 这题给了 
	

	return 0;

}
