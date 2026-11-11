#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
inline int QuickRead(){
	int flag=1,res=0;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(('0'<=ch&&ch<='9')){
		res=res*10+(ch-'0');
		ch=getchar();
	}
	return flag*res;
}
int point[maxn],last[maxm],n,m,ans[maxm];
stack<int> stk;
bool vis[maxm];
inline bool CheckA(){
	for(register int i=1;i<=n-1;i++)
		if(point[i]>point[i+1])
			return false;
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=QuickRead(),m=QuickRead();
	for(register int i=1;i<=n;i++)point[i]=QuickRead(),last[point[i]]=i;
	if(CheckA())for(register int i=1;i<=m;i++)printf("%d ",last[i]);
	else{
		if(m==1)printf("%d\n",n);
		else if(m==2){
			if(point[n]==1)printf("%d %d\n",n,n-1);
			if(point[n]==2)printf("%d %d\n",n-1,n);
		}else{
			for(register int Game=1;Game<=n;Game++){
				for(register int i=Game;i<=n;i++){
					if(vis[point[i]])
						while(!stk.empty()&&stk.top()!=point[i])
							vis[stk.top()]=false,stk.pop();
					else vis[point[i]]=true,stk.push(point[i]);
				}
				while(!stk.empty())ans[stk.top()]++,stk.pop();
				for(register int i=1;i<=m;i++)vis[i]=false;
			}
			for(register int i=1;i<=m;i++)printf("%d ",ans[i]);
		}
	}
	return 0;
}
/*
一张牌出现次数减少只有可能是被消除，除此以外没有其他方法
初始可以记 last_i 为点数为 i 的牌最后出现的位置
初始答案即为：

last_1 last_2 last_3 ... last_m 

3 1 2 1 3 2 3 1 2 1
*/
