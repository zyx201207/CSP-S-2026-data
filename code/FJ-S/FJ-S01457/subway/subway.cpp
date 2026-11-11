#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long g[1005];
long long k[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
		for(int j=0;j<m;j++){
			cin>>w[j];
		}
		for(int j=0;j<n;j++){
			int a,t;
			cin>>a>>t;
			g[j]=a;
			k[j]=t;
		}
		for(int j=0;j<q;j++){
			int x,y;
			cin>>x>>y;
			int ans=0,u=0,f=0;
			for(int b=0;b<m;b++){
					if(g[b]==x&&u==0){
						ans=ans+w[b]+k[b];
						++u;
					}
					if(g[b]==y&&f==0){
						ans+=w[b]+k[b];
						++f;
					}
			}
			cout<<ans<<endl;
		}
		return 0;
}
