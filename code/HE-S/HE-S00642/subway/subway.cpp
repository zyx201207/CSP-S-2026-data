#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int to;
	int wei;
	int id;
}edj[500010];
int ans=0x3f3f3f;
int c,n,m,d,q;
int a[500010];
int edje[510][500010];
int x[100010],y[100010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	while(int j=1;j<=n;j++){
		int tot;
		cin>>tot;
		for(int i=1;i<=tot;i++){
			cin>>edj[i].to>>edj[i].wei;
			int ttt=edj[i].wei;
		}
		for(int i=1;i<=tot;i++){
			edje[edj[i].to][edj[i+1].to]==1;
			edje[edj[i+1].to][edj[i].to]==1;
		}
		for(int i=1;i<=q;i++){
			cin>>x[i]>>y[i];
			cout<<i*ttt+a[x[i]]+a[y[i]]<<'\n';
		}
	}
	return 0;
}
//数据水一点，求你了qwq 
