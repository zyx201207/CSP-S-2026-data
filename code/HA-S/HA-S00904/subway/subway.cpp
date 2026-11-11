#include<bits/stdc++.h>
using namespace std;
struct qw{
	int jd,sj;
};
struct qwe{
	int jin,zs,xx;
	qw jd[501];
}a[505];
int n,m,sb,sm,sqj,tu[505][505],ans=INT_MAX;
int sbm(int x,int y,int ss){
	if(x==y){
	return ss;
	}
	for(int i=1;i<=a[x].zs;i++){
		if(a[x].jd[i].jd!=-1&&tu[x][a[x].jd[i].jd]==0){
		tu[x][a[x].jd[i].jd]=-1;
		ans=min(ans,sbm(a[x].jd[i].jd,y,ss+a[x].jd[i].sj));
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>sb>>n>>m>>sm>>sqj;
	memset(tu,0,sizeof(tu));
	for(int i=1;i<=m;i++){
		cin>>a[i].jin;
	}
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>a[i].zs;
		for(int o=1;o<=a[i].zs;o++){
			cin>>x>>y;
			if(x==i){
				a[i].xx=y;
				a[i].jd[o].jd=-1;
			}
			else {
				a[i].jd[o].jd=x;a[i].jd[o].sj=y;
			}
		}
	}
	
	for(int i=1;i<=sqj;i++){
		cin>>x>>y;
		sbm(x,y,a[x].jin+a[y].jin+a[x].xx+a[y].xx);
		cout<<ans;
	}
	}
