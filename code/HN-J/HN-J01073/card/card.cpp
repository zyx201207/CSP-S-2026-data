#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N]; 
int q[N];
int st=1,ed=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	bool f=1;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
	}
	if(f){
		rep(i,1,n){
			ans[a[i]]=i;
		}
	}else {
		rep(i,1,n){
		if(a[i]!=a[i-1]){
			ed=1;
			q[1]=0;
			rep(j,i,n){
			rep(k,st,ed-1){
				if(q[k]==a[j]){
					ed=k;
				}
			}
			q[ed++]=a[j];
		}
		}
		
		rep(k,st,ed-1){
			ans[q[k]]++;
		}
	}
	}
	
	rep(i,1,m)cout<<ans[i]<<' ';
	return 0;
}
//T123好水啊
//T4 没看懂
//12+12+4=28pts。
//正解是啥啊
//T1红 T2黄 T3 绿 T4 绿-青 
//冰冰冰  
//怎么那么多人T2不会 
//人均260pts有感觉吗
//纯暴力一等
//比上次T2T3难一点，但暴力都能一等
//J难S应该会简单吧
//记得上次J是个蓝题T4
//CSPS rp++
//祝我啊哈十连双金，银狼直接满魂
//mhy我翁星呢，我昔涟呢?
//4.7送2个五星。一个星魂。
//理解啊哈 赞美啊哈 成为啊哈 
//啊哈 > 贪饕吧
//啊哈吃皮蛋说是
// 还能看啊哈和黑大帅，mhy可以的
//怎么还不下考啊啊啊啊啊啊啊啊啊啊啊 啊啊啊啊啊啊啊 啊啊啊 啊啊啊啊啊 啊啊啊 啊啊啊啊 啊啊啊啊啊啊 啊啊啊啊啊啊啊啊 啊啊 啊啊啊啊啊
//啊哈 
//不好 luogu 被 black客攻击了 
//freopen(".in","r",stdout);
//freopen(".out","r",stdout);
//freopen(".in","w",stdin);
//freopen(".out","w",stdin);
//feropen(".in","r",stdin);
//freopen(".ans","w",stdout);
//freopen(".in","r'，stdin)
 
