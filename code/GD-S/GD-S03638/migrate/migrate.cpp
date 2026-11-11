#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
ll xg[2000005],sg[2000005],n,d,x[2000005],T,c
,qw[2000005], hw[2000005],qls[2000005],hls[2000005],
yql[2000005],yhl[2000005];
// w:无多条长度 
int main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			qls[i]=hls[i]=yql[i]=yhl[i]=0;
			scanf("%lld",&x[i]);
		}
		for(ll i=1,j=1;i<=n;i++){
			while(j<n&&x[j+1]<=x[i]+d){
				j++;
			}
			if(i==j){
				xg[i]=-1;
			}
			else{
				xg[i]=j;
			}
		}
		for(ll i=n,j=n;i>=1;i--){
			while(j>1&&x[j-1]>=x[i]-d){
				j--;
			} 
			if(i==j)sg[i]=-1;
			else sg[i]=j;
		}
		for(ll i=1;i<=n;i++){
			qw[i]=0;
			if(sg[i]!=-1&&xg[sg[i]]==i){
				qw[i]=qw[sg[i]]+1;
			}
			if(xg[i]!=-1){
				qls[xg[i]]+=((sg[xg[i]]>=i)?qls[i]:0)+1;
				yql[xg[i]]+=((sg[xg[i]-1]>=i)?qls[i]:0)+1;
//				cout<<xg[i]<<"FFF"<<i<<' '<<qls[i]<<' '<<qw[i]<<' '<<hls[xg[i]]<<endl;
			}
			if(qls[i]<qw[i]){
//				cout<<i<<'|'<<sg[i]<<' '<<qls[i]<<' '<<qw[i]<<endl;
//				cout<<xg[sg[i]]<<' '<<qw[sg[i]]<<' '<<qls[sg[i]]<<endl;
			}
		}
//		cout<<hls[3]<<endl;
		for(ll i=n;i>=1;i--){
			hw[i]=0;
			if(xg[i]!=-1&&sg[xg[i]]==i){
				hw[i]=hw[xg[i]]+1;
			}
			if(sg[i]!=-1){
				hls[sg[i]]+=((xg[sg[i]]<=i)?hls[i]:0)+1;
				yhl[sg[i]]+=((xg[sg[i]+1]<=i)?hls[i]:0)+1;
//				cout<<sg[i]<<"FFF"<<i<<' '<<hls[i]<<' '<<hw[i]<<' '<<hls[sg[i]]<<endl;
			}
		}
		ll ans=0;
//		for(ll i=1;i<=n;i++){
//			cout<<i<<"|:"<<sg[i]<<' '<<xg[i]<<' '<<qw[i]<<' '<<hw[i]<<endl;
//		}
		for(ll i=1;i<n;i++){
			ll j=i+1;
			if(xg[i]==-1||sg[j]==-1)continue;
//			if((!qw[j])||(!hw[i]))continue;
			if(xg[i]<=j||sg[j]>=i)continue;
//			cout<<i<<' '<<j<<' '<<hls[i]<<' '<<qls[j]<<endl;
			ans+=(yql[j])*(yhl[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
zuo fa jia le dan wo wan quan bu zhi dao jia zai na,caobi

Oh No!! i'm right!!! guo da yang li le,
danshi di 4 ge hen man.
man!!!

hyxggsama saikyo

zui jin zai kan wuyuxilie,gan jue bu cuo.
,jiu shi cha hua bi jiao jian lou.

jin tian shang wu wo you da le yi bian yueji,gongzhuxian Good End.

qi shi wo xian zai gan jue fan dao mei you TE lai gan jue.

xiang hu ai lian que bu de bu li bie
,dan ji yi yu yue ding yong yuan buhui bei yi wang.

xia qi lai wenxueshaonu de di ba juan hao xian ye shi zhe ge gan jue.

ai,zai guo yi ge yue jiu yao AFO le.

wo yu OI de feng li shi fou ye jiang ru ci dong ren xin xian ne.

I love OI.

*/
// 什么也可以抛弃，什么也不能忘记
// 今天的欢乐将是明天永恒的回忆 
