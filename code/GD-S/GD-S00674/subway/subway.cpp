//14:40写完T1，然后T2都完全看不懂了
//100分跑路得了
//睡觉吧
#include<bits/stdc++.h>
#define MAXN 510
#define MAXM 500100
using namespace std;
int c,n,m,d,q,w[MAXM],k[MAXM];
vector<int>a[MAXN],t[MAXN]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<"";
	}
	return 0;
}
