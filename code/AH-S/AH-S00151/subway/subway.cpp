#include <bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long c,n,m,d,q;
long long w[N],k[N],t[N];
struct Node{
	long long station,dis;
}p[N];
bool cmp(Node x,Node y){
	if(x.station!=y.station){
		return x.station<y.station;
	}
	else return x.dis<y.dis;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	long long sl=0;
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		sl+=k[i];
		for(long long j=1;j<=k[i]*2;j++){
			cin>>t[i];
			if(j%2==1){
				p[n+1/2].station=t[i];
			}
			else p[n/2].dis=t[i];
		}
	}
	sort(p+1,p+n+1,cmp);
	for(long long dz=1;dz<=q;dz++){
		long long x,y;
		cin>>x>>y;
		long long sum=0;
		for(long long i=x;i<=y-1;i++){
			sum+=p[i].dis;
		}
		cout<<w[x]+p[x].dis+sum+w[y]<<endl;
	}
	return 0;
}
