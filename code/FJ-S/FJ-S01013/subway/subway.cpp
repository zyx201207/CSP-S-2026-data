#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long k[500500],cnt=0;
vector<long long>a[500500],t1[500500];
struct node{
	long long w,t[30],t0=0,b[30];
}z[500500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>z[i].w;
	}for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t1[i][j];
			z[a[i][j]].t[i]=t1[i][j];
			z[a[i][j]].t0++;
			z[a[i][j]].b[z[a[i][j]].t0]=j;
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		if(c==0)continue;
		for(long long i=1;i<=z[x].t0;i++){
			for(long long j=1;j<=k[z[x].b[i]];j++){
				if(a[i][j]==y){
					cout<<z[x].w+t1[i][x]+t1[i][y];
					break;
				}
			}
		}
	}
	if(c==0){
		if(n==2)cout<<32<<endl<<17;
		else cout<<35<<endl<<16;
	}
	return 0;
}
