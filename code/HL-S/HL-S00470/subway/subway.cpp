#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a,b,c,n,m,d,q,tot,jin[N],k,t,huan[N],dui[N],a1,t1,x,y,sum=1e7;
struct node{
	int he,ne,ed,v,num;
}xian[N];
void add(int x,int y,int z){
	xian[++tot].v=y;
	xian[tot].num=z;
	xian[tot].ne=xian[x].he;
	xian[x].he=tot;
}
void dfs(int x,int y){
	for(int i=xian[x].he;i;i=xian[i].ne){
		if(xian[x].v==0||xian[x].v==y) return;
		int ans;
		ans+=huan[xian[i].v];
		dfs(xian[i].v,y);
		sum=min(ans,sum);
		ans=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&jin[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&k,&a,&t);
		huan[a]+=t;
		for(int j=1;j<k;j++){
			scanf("%d%d",&a1,&t1);
			huan[a1]=t1;
			add(a,a1,i);
			a=a1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dfs(x,y);
		cout<<sum+jin[x]+jin[y]<<endl;
		sum=1e7;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//    for(int i=1;i<=5;i++){
//    	cin>>a>>b>>c;
//    	add(a,b,c);
//	}
//	for(int i=he[1];i;i=ne[i]){
//		cout<<v[i];
//	}