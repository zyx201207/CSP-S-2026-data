#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long c,n,m,d,q; 
long long w[N],k[N];
struct node{
	long long a,t;
}K[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>K[i][j].a>>K[i][j].t;
		}
	} 
	while(q--){
		long long x,y,cnt=0;
		cin>>x>>y;
		cnt=cnt+w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(K[i][j].a==x) cnt+=K[i][j].t;
			}
		}
		for(int i=1;i<=n;i++){
			long long s=k[i];
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<=k[i];l++){
					if(K[i][s].a==y) break;
					if(K[j][l].a==K[i][s].a && x==K[i][s].a){
						cnt=cnt+K[i][s].t+K[j][l].t;
					}
				}
			}
			s++;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 


