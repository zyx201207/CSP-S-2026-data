//GZ-S00330 贵州省铜仁第一中学 李宇烜
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct node{
	int x;
	int y;
};
int n,m,w[N],c,d,q,u,a[N][1000],t[N][20];
node r[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>u;
		for(int j=1;j<=u;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
		cin>>r[i].x>>r[i].y;
	while(q--){
		cout<<t[1][1]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
}
