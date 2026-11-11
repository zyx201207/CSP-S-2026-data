#include<bits/stdc++.h>
using namespace std;
struct{
int a;
int t;	
}v[500001],fir[500001];
int c,n,m,d,q,w[1000000];
long long k[100000],ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v[j].a>>v[j].t;
			if(i==1){
				for(int z=1;z<=k[i];z++){
					fir[z].a=v[z].a;
					fir[z].t=v[z].t;
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		bool g=1;
		for(int z=1;z<=k[1];z++){
		if(fir[z].a==x||fir[z].a==y){
		ans+=fir[z].t;
		g=0;
		}}
		if(g)ans+=10;
		cout<<ans<<endl;
		ans=0;
			}
	return 0;
}
