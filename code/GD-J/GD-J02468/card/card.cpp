#include<bits/stdc++.h>
#define IL inline
#define ll long long
#define ull unsigned long long
#define ri register int
#define F(i,a,b) for(ri i=a;i<=b;i++)
#define FF(i,a,b) for(ri i=b;i>=a;i--)
#define i128 __int128
#define vec vector
using namespace std;
const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
int n,m,a[N],cnt[N];
stack<int> st;
bool ins[N],vis[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	F(i,1,n) cin>>a[i];
	F(i,1,n){
//		cout<<"game:"<<i<<'\n';
		while(!st.empty()){
			int v=st.top(); st.pop();
			ins[v]=0;
		}
		F(j,i,n){
//			cout<<"a_j:"<<a[j]<<'\n';
			if(!ins[a[j]]){
				st.push(a[j]);
				ins[a[j]]=1;
			}
			else{
				int v;
				do{
					v=st.top(); st.pop();
					ins[v]=0;
//					cout<<"v:"<<v<<'\n';
				}
				while(v!=a[j]);
				st.push(a[j]);
				ins[a[j]]=1;
			}
		}
		F(j,1,m){
			if(ins[j]) cnt[j]++;
//			cout<<"cnt_"<<j<<":"<<cnt[j]<<"\n";
		}
	}
	F(i,1,m) cout<<cnt[i]<<' ';
	return 0;
}
/*
in:
10 3
3 1 2 1 3 2 3 1 2 1
out:
10 3 3
*/

/*
整理下思路
显然就是，如果要判 a_i 的话，可以维护一个栈，每次入栈前判一下栈内有没有相同元素，如果有的话就一直弹栈
然后问题变成了怎么计数
每局游戏结束时扫一遍 ins 数组，如果非 0 的话说明这局游戏是有 i 的，那么 cnt[i]++
注意开始前要先清空栈 

不是我怎么看错题了
感觉要玩

咋优化呢
似乎这个游戏倒着做的话 
后面的状态显然就和前面的有关

md 写不完了 
*/
