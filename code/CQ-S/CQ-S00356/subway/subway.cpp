#include<bits/stdc++.h>
using namespace std;
long long w[500005],s[505][505],p[505],ss[500005],K[505],h[505][505];
vector<long long> z[505],t[505],g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	long long C,n,m,d,q,ans,x,y; 
	cin>>C>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			s[i][j]=1e18;
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>K[i];
		for(long long j=1;j<=K[i];j++){
			cin>>x>>y;
			z[i].push_back(x);
			g[x].push_back(j); 
			h[x][++ss[x]]=i;
			p[x].push_back(i*30+ss[x]);
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<K[i];j++){
			for(long long k=1;k<=ss[z[i][j]];k++){
				s[h[z[i][j]][k]][i]=min(s[h[z[i][j]][k]][i],t[i][j]+t[h[z[i][j]][k]][g[z[i][j]][p[h[z[i][j]][k]]]]);
				s[i][h[z[i][j]][k]]=min(s[i][h[z[i][j]][k]],t[i][j]+t[h[z[i][j]][k]][g[z[i][j]][p[h[z[i][j]][k]]]]);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		s[i][i]=0;
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(s[i][k]+s[k][j]<s[i][j]){
					s[i][j]=s[i][k]+s[k][j];
				}
			}
		}
	}
	for(long long i=1;i<=q;i++){
		ans=1e18;
		cin>>x>>y;
		for(long long j=1;j<=ss[x];j++){
			for(long long k=1;k<=ss[y];k++){
				ans=min(ans,s[h[x][j]][h[y][k]]+t[h[x][j]][g[x][p[j]]]+t[h[y][k]][g[y][p[k]]]+w[x]+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5 
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
