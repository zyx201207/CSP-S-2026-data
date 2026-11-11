#include<bits/stdc++.h>
using namespace std;
struct qs{
	int l,r;
};
int c,n,m,d,q,in[1000001];
int ans[1001][1001]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&in[i]);
	}
	if(c>=7&&c<=11){
		int x=0,y=0,xx=0,yy=0;
		vector<qs>ve[1001];
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x==1){
				scanf("%d%d",&x,&y);
			}else{
				scanf("%d%d%d%d",&x,&y,&xx,&yy);
				ve[x].push_back({xx,y+yy});
				ve[xx].push_back({x,y+yy});
			}
		}
		int s,f;
		for(int i=1;i<=q;i++){
			int aa[1001]={},mi=0,mii=0,da;
			scanf("%d%d",&s,&f);
			if(ans[s][f]!=0){
				printf("%d\n",ans[s][f]+in[s]+in[f]);
				continue;
			}
			if(ans[f][s]!=0){
				printf("%d\n",ans[f][s]+in[s]+in[f]);
				continue;
			}
			aa[s]=1;
			da=s;
			for(int j=0;j<ve[s].size();j++){
				ans[s][ve[s][j].l]=ve[s][j].r;
			}
			for(int j=1;j<m;j++){
				mi=0,mii=0;
				for(int k=1;k<=m;k++){
					if(aa[k])continue;
					if(ans[s][k]==0)continue;
					if(ans[s][k]<mi||mi==0){
						mi=ans[s][k];
						mii=k;
					}
				}
				da=mii;
				aa[mii]=1;
				for(int k=0;k<ve[da].size();k++){
					ans[s][ve[da][k].l]=min(ve[da][k].r+ans[s][da],ans[s][ve[da][k].l]);
					if(ans[s][ve[da][k].l]==0)ans[s][ve[da][k].l]=ve[da][k].r+ans[s][da];
				}
			}
			printf("%d\n",ans[s][f]+in[s]+in[f]);
//			if(aa[f]==0)cout<<0<<"\n";
		}
	}
	
	return 0;
}
