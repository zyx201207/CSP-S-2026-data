//GZ-J00052 贵阳市第一中学 敖翔蓝天 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2555005
ll n,m,a[N],ans[N],hdl=-1,ylg;
ll zyg[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		hdl=max(hdl,a[i]);
		zyg[a[i]]++;
	}
	if(m==1){
		cout<<hdl;
		return 0;
	}
	if(m==n){
		ylg=a[1];
		for(int i=1;i<=n;i++){
			ylg&=a[i];
		}
		return 0;
	}
	if(m==n-1){
		if(zyg[3]>=n-1) cout<<3;
		else if(zyg[2]+zyg[3]>=n-1) cout<<2;
		else if(zyg[1]+zyg[3]>=n-1) cout<<1;
		else if(zyg[4]>=n-1) cout<<4;
		else cout<<0;
		return 0;
	}
	if(m==2){
		hdl=0;
		for(int j=1;j<=n;j++){
			for(int i=j+1;i<=n;i++){
				ll m=a[i]&a[j];
				hdl=max(hdl,m);
			}
		}
		cout<<hdl;
		return 0;
	}
}
//____30分 
//胡大佬牛福！
//Trick||Treat!
//S+J=399 J=254 S=145
/*
	J要被制裁了-------------------------- 
	567267067167067267267067167267167067267067767067167
	去掉67看看呢：胡大佬的sfzh去掉最后一位 
*/
