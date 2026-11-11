#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long have,a[N],cha[N],ans=-1;
int n;
priority_queue<long long,vector<long long>,greater<long long> > f;
void init(){
	scanf("%d%lld",&n,&have);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);		//原始数据 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		cha[i]=a[i]-a[i-1];		//上一个到这里要多少 
	return;
}
void solve(){
	long long need=0,cnt=1;	//前面有多少个不要的 
	for(int i=1;i<=n;i++){
		long long goal=a[i];
		need=need+cha[i]*(i-cnt);
		f.push(goal);
		while(need>have && f.size()){  //不够用了 把最优留下 剔除最差的
			//能量值最小的能量球到大目标能量球要的更多
			//可以更优
			need=need-(goal-f.top());
			f.pop();
			cnt++;
		}
		ans=max(ans,(long long)f.size());
	}
	printf("%lld",ans);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	solve();
	return 0;
}
//只能加一个能量值 ->只能从左往右去加 
/*
5 5
1 2 4 8 9
*/
