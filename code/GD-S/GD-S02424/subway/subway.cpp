#include<bits/stdc++.h>
using namespace std;
struct node{
	int x2,y2;
}x[510][20010];
int c,n,m,d,q,a[500010],x1,y1;
int dfs(int x3,int y3,int sum1,int sum2){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]!=0){
				dfs(a[i],x[i][j].x2,min(sum1,sum2),sum2+x[i][j].y2);
			}
		}
	}
	return sum1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>x1;
		for(int j=1;j<=x1;j++){
			cin>>x[i][j].x2>>x[i][j].y2;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x1>>y1;
		if(n!=1)cout<<dfs(x1,y1,INT_MAX,a[x1]+a[y1]);
		else{
			cout<<a[x1]+a[y1]+x[1][x1].y2+x[1][y1].y2<<endl;
		}
	}
}
