#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],bj[N],cnt[N],lst[N],ds,cf[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 
	for(int i=1;i<=n;i++){
	    for(int j=i-1;j>=1;j--){
	    	if(a[j]==a[i]){
	    		lst[i]=j;
	    		break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cf[j]=1;
		for(int j=i;j<=n;j++){
			if(lst[j]==0||lst[j]<i)continue;
			if(cf[lst[j]]==0)continue;
			int tmp=lst[j];
			for(int k=tmp;k<j;k++)cf[k]=0;
		}
		for(int j=i;j<=n;j++)if(cf[j])cnt[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}
//我无疑是愤怒的，这题肯定不会 
//ds的意思是当前游戏的一种轮数吧！
//比昨天信心赛还有简单，我简直太菜了，初二连J都
//无法AK 
//倒闭了读错题目了
//如果找到一个a[i]，那上一个a[i]以前的应该都不作数了 
//每个i会让lst[i]-(i-1)的卡牌都不作数，最后查询是否作数
//显然可以利用差分数组来做
//我感觉我不太会O(n^2),但是样例3，4都过了，而且造了几个随机数据也过了
//为什么card3,card4都能过而且跑的飞快？？？ 
//目前估分100+100+100？+【24，48】=【324，348】？但不知道会不会挂 
