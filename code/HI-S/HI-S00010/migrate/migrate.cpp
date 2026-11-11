#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;//分别表示测试点编号与测试数据组数。 
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		int n,d,a[100005],c[100005],l[100005]={0},dm=0,bm=1,cm=0;//岛屿数量和海鸟一次最多能飞行的距离。
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1){
				c[i-1]=a[i]-a[i-1];
				l[i-1]=l[i-2]+c[i-1];
				if(l[i-1]-l[bm]<d){
					bm=i-1;//位置 
					cm=bm-cm;//长度 
					dm+=cm;
					cm=bm;
				}
			}
		}
		cout<<dm/2<<endl;
	}
	return 0;
}


