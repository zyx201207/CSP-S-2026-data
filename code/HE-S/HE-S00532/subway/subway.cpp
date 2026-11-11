#include<bits/stdc++.h>
using namespace std;
struct scp{
	int x;
	int y;
};//旅行
int c;//测试
int n;//总路数
int m;//地铁站数
int d;//站点最多路线经过
int q;//q次旅行 
int md[1000010]={0};//口—厅时间
int nd[510]={0};//第i个经过几个地铁站 
int ndb[510][510]={0};//第i个路线经过 第j个地铁站的时间
scp pd[1000010]={0};//描述第i次旅行 

int main(){
//	freopen("crystal.in","r",stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>md[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<k;j++){
			int a;
			cin>>a;
			cin>>ndb[i][a];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>pd[i].x>>pd[i].y;
	}
	
//	freopen("crystal.out","w",stdout);
//	fclose(stdout);
	return 0;
} 
//这是啥啊..... 
