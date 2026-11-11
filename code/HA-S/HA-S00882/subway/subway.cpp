#include<bits/stdc++.h>
using namespace std;
int read_i(){
	char re;
	int r=1;
	re=getchar();
	while(re>'9'||re<'0'){
		if(re=='-')r=-1;
		re=getchar();
	}
	int x=0;
	while(re>='0'&&re<='9'){
		x*=10;
		x+=re-'0';
		re=getchar();
	}
	return x*r;
}
int c,n,m,d,q;
int a[5001];
struct A{
	int b,e;
}cq[5001],dt[5001];
bool cmp(A R,A T){
	return R.b<T.b;
}
int b[2501][2501];
vector<int>ans[2501];
bool cf[5001];
bool st[5001];
int djst[5001];
void djstl(int yy){
	memset(st,true,sizeof(cf));
	memset(djst,0x3f,sizeof(djst));
	djst[yy]=0;
	for(int i=1;i<m;i++){
		
		int t=-1;
		for(int j=1;j<=m;j++){
			if(st[j]&&(t==-1||djst[j]<djst[t])){
				t=j;
			}
		}
		st[t]=false;
		for(int j=1;j<=m;j++){
			djst[j]=min(djst[j],djst[t]+b[j][t]+b[t][j]);
		}
	}
	for(int i=0;i<m;i++){
		ans[yy].push_back(djst[i+1]);
	}
	cf[yy]=true;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read_i(),n=read_i(),m=read_i(),d=read_i(),q=read_i();
	for(int i=1;i<=m;i++){
		a[i]=read_i();
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;i++){
		int k=read_i();
		for(int j=1;j<=k;j++){
			dt[j].b=read_i();
			dt[j].e=read_i();
			for(int w=1;w<j;w++){
				b[dt[w].b][dt[j].b]=dt[w].e;
				b[dt[j].b][dt[w].b]=dt[j].e;
			}
		}
		//cout<<"\n";
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++){
		cq[i].b=read_i();
		cq[i].e=read_i();
	}
	sort(cq+1,cq+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(!cf[cq[i].b]){
			if(!cf[cq[i].e])djstl(cq[i].b);
			else{
				printf("%d\n",ans[cq[i].e][cq[i].b-1]+a[cq[i].e]+a[cq[i].b]);
				continue;
			}
		}
		printf("%d\n",ans[cq[i].b][cq[i].e-1]+a[cq[i].e]+a[cq[i].b]);
	}
//	for(int i=1;i<=m;i++){
//		cout<<ans[1][i-1]<<" ";
//	}
	return 0;
}
