#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[505];
vector <int> tl[505];
struct jgt{
	int tc[505];
}f[505];
struct node{
	int zd,bs;
};
queue <node> u;
bool bj[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>>ai>>ti;
			tl[i].push_back(ai);
			f[ai].tc[i]=ti;
		}
	}
	while(q--){
		int ans=99999999;
		int x,y;
		cin>>x>>y;
		for(int k=1;k<=n;k++){
			if(f[x].tc[k]>0){
				u.push({x,a[x]+f[x].tc[k]});
				bj[x][k]=1;
			}
		}
		while(!u.empty()){
			node z=u.front();
			for(int i=1;i<=n;i++){
				if(f[z.zd].tc[i]>0){
					for(int j=0;j<tl[i].size();j++){
						if(bj[tl[i][j]][i]==0){
							bj[tl[i][j]][i]=1;
							int zx=tl[i][j];
							if(tl[i][j]==y){
								ans=min(ans,z.bs+f[tl[i][j]].tc[i]+a[tl[i][j]]);
							}
							for(int l=1;l<=n;l++){
								if(f[zx].tc[l]>0){
									if(tl[i][j]==y){
										ans=min(ans,z.bs+f[tl[i][j]].tc[i]+a[tl[i][j]]);
									}
									u.push({zx,z.bs+f[zx].tc[i]+f[zx].tc[l]});
									bj[zx][l]=1;
								}
							}
						}
					}
				}
			}
//			cout<<z.zd<<" "<<z.bs<<endl;
//			if(z.zd==y){
//				ans=min(ans,z.bs);
//			}
			u.pop();
		}
		cout<<ans<<endl;
	}

	return 0;
}
