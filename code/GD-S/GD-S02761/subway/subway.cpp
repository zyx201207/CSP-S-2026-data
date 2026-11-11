#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int IN=1e8;
const int M=5e5+10;
const int N=500;
ll C,n,m,D,q,mov1[M],cnt;//mov1从地铁口走到站厅，cnt地铁线路 
struct node{
	int zhan[M],val=0,sum=0;//val从该地铁站的站厅走到站台时间,zhan哪个站 
}len[N];//几号线 
struct jing{
	bool fl=0;
	int sum=0;//重复了多少条 
	int dt[30];//重复了那几条 
	int dts[30];
}dd[M];//i站 
int dfs(int l,int r,ll ans,int le){
	int qwe=IN;
	if(l==r){
		return len[le].val+mov1[l];
	}
	if(dd[l].sum>=2){
		for(int i=1;i<=dd[l].sum;i++){
			qwe=min(qwe,dfs(dd[l].dt[i],r,ans,dd[l].dts[i]));
		}
		ans+=qwe;
		return ans;
	}else{
		ans+=dfs(len[le].zhan[l],r,ans,le);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>mov1[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cnt++;
		for(int i=1;i<=k;i++){
			len[cnt].sum++;
			cin>>len[cnt].zhan[k]>>len[cnt].val;
			if(dd[len[cnt].zhan[k]].fl==1){
				dd[len[cnt].zhan[k]].sum++;
				dd[len[cnt].zhan[k]].dt[dd[len[cnt].zhan[k]].sum]=len[cnt].zhan[k];
				dd[len[cnt].zhan[k]].dts[dd[len[cnt].zhan[k]].sum]=cnt;
			}else{
				dd[len[cnt].zhan[k]].fl=1;
			}
		}
	} 
	while(D--){
		ll sa,en,ans=0;
		int sta[M],tmp=0;
		cin>>sa>>en;
		ans=ans+mov1[sa]+mov1[en];
		int qwe=IN;
		for(int i=1;i<=cnt;i++){//遍历开始点在几号线 
			for(int j=1;j<=len[i].sum;i++){
				if(len[i].zhan[j]==sa){
					qwe=min(qwe,dfs(sa,en,0,i)+len[i].val,i);
				}
			}
		}
		ans+=qwe;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
