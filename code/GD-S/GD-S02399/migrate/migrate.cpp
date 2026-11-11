#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2000010;
int pl[maxn];
int global_step,global_cnt;
int c,t;
int n,d,ans;

void input(){
	scanf("%lld %lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&pl[i]);
	}
}
void dfs(int node,int goal,int step){
	//printf("dfs : %lld %lld %lld\n",node,goal,step);
	if(step>global_step)return;
	if(node==goal){
		if(step<global_step){
			global_step=step;
			global_cnt=1;
		}else{
			global_cnt++;
		}
	}
	for(int i=goal;i>=node+1;i--){
		if(pl[i]-pl[node]<=d){
			dfs(i,goal,step+1);
		}
	}
}
void solve(){
	//force code
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			global_step=maxn;
			dfs(u,v,0);
			//printf("%lld - %lld : %lld\n",u,v,global_cnt);
			if(global_cnt==2){
				ans++;
			}
		}
	}
}
void output(){
	printf("%lld",ans);
}
//void LunAsk(){}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	input();
	solve();
	output();
	return 0;
}
/*
kC-migrate :
for k+2 point l,a1,a2...,ak,r ;pl<pa1<pa2<...<pak<pr and in range [pl,pr] only has k+2 point(them) 
pak-pl<=d ; rz-pa1<=d ; pr-pl>d
we call (l,a1,a2...,ak,r) a kC-migrate

a acceptable (u,v) has and only has one 2C-migrate and some 1C-migrate(maybe has no 1C-migrate). 
3C-migrate and more are unacceptable

*/









/*
I'm so tired...
at 16:21

expect to get 8 FEN
*/
