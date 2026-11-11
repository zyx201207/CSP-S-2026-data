#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long c,n,m,d,q,ans;
long long w[N];
struct Node{
	long long a,t;
}l[N];
//long long cost[N][N];
//void floyd(){
//	
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>l[i].a>>l[i].t;
	while(q--){
		long long x,y,ans=0;
		cin>>x>>y;
		for(int i=x;i<=y;i++)
			ans+=w[i];
		cout<<ans<<"\n";
	}//Ã»¿´¶® W_W 
	return 0;
}

