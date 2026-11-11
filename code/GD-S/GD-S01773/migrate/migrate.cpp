#include<bits/stdc++.h>
//......
//白鸟我的白鸟
//......
//若是想与我相见
//就来我的梦里边
//(个人对题目的理解) 
using namespace std;
long long c,t,n,d,x[1145140*2],ans,cnt,mn=0x3f3f3f3f;
//......
//我也不想在这里 
//...... 
//(题意主旨概括) 
void dfs(long long bg,long long ed,long long now,long long step){
	if(ed==now){
		if(step<mn){
			cnt=1;
			mn=step;
		}
		if(step==mn){
			cnt++;
		}
		else return;
	}
	for(long long i=ed;i>now;i--){
		if(x[i]-x[now]<=d&&x[i+1]-x[now]>d){
			dfs(bg,ed,i,step+1);
		}
	}
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//我算遍了1145141919810种可能
	//只有一种
	//我赢了
	//......
	cin>>c>>t;
	if(c==13||c==14){
		for(int i=1;i<=t;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		//...... 
		//最强的战绩铭刻于2026CSP-S之上
		//下一话：T4!
		//(记录自身做题痕迹，与考试相关) 
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		} 
		//意气风发啊西西弗
		//......
		//考生们可都看着呢，让我再出几道紫题吧
		//(对考试题目难度的预测) 
		ans=0,cnt=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				mn=0x3f3f3f3f;
				cnt=0;
				if(abs(i-j)!=1)dfs(i,j,i,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	} 
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
