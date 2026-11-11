#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=1e5+50000;
const int K=2*1e5+5;
int c,n,m,d,q;
int k[N];
int w[M];
struct node{
	int a,t;
}s[N][K];//第几条线路+第几个地铁站 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s[i][j].a>>s[i][j].t;
		}
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int xx=-1,yy=-1;
			for(int j=1;j<=k[i];j++){
				if(s[i][j].a==x)xx=j;
				if(s[i][j].a==y)yy=j;
			}
			if(xx!=-1&&yy!=-1){
				ans=w[x]+s[i][xx].t+s[i][yy].t+w[y];
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
Oct31==Dec25?
*/
