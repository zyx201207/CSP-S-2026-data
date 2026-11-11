#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y; 
struct nidao{
	int zhan;
	int tingtaitime;
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int kouting[m+1];
	//输入第二行 
	for (int i=1;i<=m;i++){
		cin>>kouting[i];
	}
	//输入地铁线路
	for (int i=1;i<=n;i++){
		int zhanshu=0;
		cin>>zhanshu;
		int xianlu[n][zhanshu];
		for (int j=1;j<=zhanshu;j++){
			cin>>xianlu[i][j];
		}
		cout<<11<<'\n';
	} 
	//输入地点
	 
	return 0;
}
