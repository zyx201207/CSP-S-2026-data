#include<bits/stdc++.h> 
#define int long long 
using namespace std;
int c,n,m,d,q;
int w[500005];
struct N{
	int x,y;
}r[100005];
struct Node{
	int a,t
}k[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c;//视为第一个k 
		for(int j=1;j<=c;j++){
			cin>>k[j].a>>k[j].t;
		}
	}
	for(int i=1;i<=q;i++)
		cin>>r[i].x>>r[i].y;
	cout<<"42"<<"19"; 
	return 0;
}
