#include<bits/stdc++.h>
using namespace std;
int w[100005];
struct p{
	int k;
	int sta[100005],ti[100005];
}sub[505];
struct pe{
	int beg,en;
}tri[100005];
int u[100005],e[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>sub[i].k;
		for(int j=1;j<=sub[i].k;j++) cin>>sub[i].sta[j]>>sub[i].ti[j];
	}
	for(int v=1;v<=q;v++){
		cin>>tri[v].beg>>tri[v].en;
		if(n==2){
			int y=0;
			for(int i=1;i<=sub[1].k;i++){
				for(int j=1;j<=sub[2].k;j++){
					if(sub[1].sta[i]==sub[2].sta[i]) u[++y]=i,e[y]=j;
				}
			}
			int d=0; bool f;
			int h1=0,h2=0;
			for(int j=1;j<=sub[1].k;j++){
				if(tri[v].beg==sub[1].sta[j]){
					d++; h1=j;
				}
				if(tri[v].en==sub[1].sta[j]){
					d++; h2=j;
				}
			}
			if(d==2){
				int ans=w[tri[v].beg]+w[tri[v].en]+sub[1].ti[h1]+sub[1].ti[h2];
				cout<<ans<<endl; continue;
			}
			else if(d==0){
				int ans=w[tri[v].beg]+w[tri[v].en]+sub[2].ti[h1]+sub[2].ti[h2];
				cout<<ans<<endl; continue;
			}
			else if(d==1&&h2==0){
				for(int j=1;j<=sub[2].k;j++){
					if(tri[v].en==sub[2].sta[j]){
						h2=j;
					}
				}
				int ans=0;
				for(int i=1;i<=y;i++){
					int sum=w[tri[v].beg]+w[tri[v].en]+sub[1].ti[h1]+sub[2].ti[h2]+sub[1].ti[u[i]]+sub[2].ti[e[i]];
					ans=max(ans,sum);
				}
				cout<<ans<<endl; continue;
			}
			else if(d==1&&h1==0){
				for(int j=1;j<=sub[1].k;j++){
					if(tri[v].en==sub[1].sta[j]){
						h1=j;
					}
				}
				int ans=0;
				for(int i=1;i<=y;i++){
					int sum=w[tri[v].beg]+w[tri[v].en]+sub[2].ti[h1]+sub[1].ti[h2]+sub[1].ti[u[i]]+sub[2].ti[e[i]];
					ans=max(ans,sum);
				}
				cout<<ans<<endl; continue;
			}
		}
		if(7<=c&&c<=11){
			
		}
	}
	return 0;
}
