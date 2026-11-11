#include<iostream>
using namespace std;
struct way{
	long long to,lng;
}t[500001][21];
long long c,n,m,d,q,w[500001],k[501],b[500001],x,y;
bool f[500001][501],fl[500001];
long long ans(long long x,long long y){
	if(x==y) return 0;
	long long an=(1ll<<60);
	way s;
	for(int i=1;i<=d;i++){
		s=t[x][i];
		if(s.to>0){
			if(!fl[s.to]){
				fl[s.to]=1;
				for(long long j=1;j<=m;j++) if(f[j][s.to]&&j!=x) for(int k=1;k<=d;k++) if(t[j][k].to==s.to) an=min(an,ans(j,y)+s.lng+t[j][k].lng);
				fl[s.to]=0;
			}
		}else break;
	}
	return an;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x;
			f[x][i]=1;
			t[x][++b[x]].to=i;
			cin>>t[x][b[x]].lng;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<ans(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
