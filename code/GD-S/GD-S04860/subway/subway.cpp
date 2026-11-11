#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
const int _S=5e4+1;
int n,m,w[_S],k[505],a[505][_S],t[505][_S],d,mline_s[_S][505],mline_n[_S];
//bool check(int ss,int tt){
//	return vis[ss][tt]||vis[tt][ss];
//}
int seach(int cs_s,int cs_t){
	int tot=0,line; bool lkd=0;
	//判断起点与终点能否通过一条线路连接
	for(int xh1=1;xh1<=mline_n[cs_s];xh1++)
		for(int xh2=1;xh2<=mline_n[cs_t];xh2++)
			if(mline_s[cs_s][xh1]==mline_s[cs_t][xh2]){
				lkd=1; line=mline_s[cs_s][xh1]; break;
			}
	if(lkd) return t[line][cs_s]+t[line][cs_t];
	//枚举所有可能的中间车站，并准备进一步枚举 
	for(int xh=1;xh<=m;xh++){
		if(xh==cs_s || xh==cs_t) continue;
		tot=max(tot,seach(cs_s,xh)+seach(xh,cs_t));
	}
	return tot;
}
int main(){
	int Q,ccccc;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&ccccc,&n,&m,&d,&Q);
	for(int xh=1;xh<=m;xh++)
		scanf("%d",w+xh);
	for(int xh1=1;xh1<=n;xh1++){
		scanf("%d",k+xh1);
		for(int xh2=1;xh2<=k[xh1];xh2++){
			scanf("%d%d",a[xh1]+xh2,t[xh1]+xh2);
			mline_s[a[xh1][xh2] ][++mline_n[n]]=xh1;
		}
	}
	while(Q--){
		int s,t,ans=0;
		scanf("%d%d",&s,&t);
		ans+= (w[s]+w[t] )+seach(s,t);
		printf("%d\n",ans);
	}
	return 0;
}
