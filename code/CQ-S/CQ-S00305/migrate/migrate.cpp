#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128
#define mkp make_pair
const int N=2e6+5;
struct Point{
	int val,cnt;
	Point operator+(const Point &x)const{
		if(val==x.val)return (Point){val,min(3ll,cnt+x.cnt)};
		else if(val<x.val)return (Point){val,cnt};
		else return x;
	}
}dp[N];
int cid,t,L[N],R[N],maxn=1e6,a[N],d[N],n,D,pos[N],len,ans,col[N];
void updt(int x,int k){
	col[x]=min(maxn,col[x]+k);
} 
void solve2(int now){
	for(int i = now;i <= n;i++)dp[i]=(Point){n+1,0};
	dp[now]=(Point){0,1};
	for(int i = 0;i <= n;i++)col[i]=0;
	col[0]=1;int nowl=0,lst = now;
	for(int i = now+1;i <= n;i++){
		while(lst<L[i]){
			col[dp[lst].val]-=dp[lst].cnt;
			lst++;
		}
		while(!col[nowl]&&nowl<=n)nowl++;
		dp[i].val=nowl+1;dp[i].cnt=min(3ll,col[nowl]);
		col[dp[i].val]+=dp[i].cnt;/*
		for(int j = i-1;j >= now;j--){
			if(a[i]-a[j]>D)break;
			Point now =(Point){dp[j].val+1,dp[j].cnt};
			dp[i]=dp[i]+now;
		}*/
	}
	for(int i = now+1;i <= n;i++){
		if(dp[i].val<=n&&dp[i].cnt==2){
			ans++;
//			cout << now << " " << i << " " << dp[i].val << " " << dp[i].cnt << "\n";		
		}
	}
} 
void solve1(int now){
	for(int i = now;i <= n;i++)dp[i]=(Point){n+1,0};
	dp[now]=(Point){0,1};
	for(int i = now+1;i <= n;i++){
		for(int j = i-1;j >= now;j--){
			if(a[i]-a[j]>D)break;
			Point now =(Point){dp[j].val+1,dp[j].cnt};
			dp[i]=dp[i]+now;
		}
	}
	for(int i = now+1;i <= n;i++){
		if(dp[i].val<=n&&dp[i].cnt==2){
			ans++;
//			cout << now << " " << i << " " << dp[i].val << " " << dp[i].cnt << "\n";		
		}
	}
}
void work(){
	cin >> n >> D;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1,now=1;i <= n;i++){
		while(now<n&&a[now+1]-a[i]<=D)now++;
		R[i]=now;
	}
	for(int i = n,now=n;i >= 1;i--){
		while(now>1&&a[i]-a[now-1]<=D)now--;
		L[i]=now;
	}
	if(cid<=6){
		ans=0;
		for(int i = 1;i <= n;i++)solve1(i);
		cout << ans << "\n";
	}
	else if(cid<=10){ans=0;
		for(int i = 1;i <= n;i++)solve2(i);
		cout << ans << "\n";
	}else if(cid>=13&&cid<=14){ans=0;int nowl =1;
		for(int i = 1;i <= n;i++)col[i]=0;
		for(int i = 1;i <= n;i++){
			while(nowl<L[i]){
				col[R[nowl]]++;
				nowl++;
			}ans+=col[L[i]+1];
		}cout << ans << "\n";
	}else{
		ans=0;//d=ak+k-1
		int d1 = a[2]-a[1],k=D/d1;
		if(k<=1){
			cout << "0\n";
			return;
		}
		for(int i = 1;i <= n;i++)if(i+(2*k-1)<=n)ans++;
		cout << ans << "\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> cid >> t; 
	while(t--)work();
	return 0;
}
/*
路径长度应该是飞行次数吧
感觉确实应该有紫吧
对于一组(i,j)
考虑贪心。
先从i每次尽量跳远，然后最后跳到j
然后考虑调整路径
调整次数可以看出来怎么做
就是实际上做的是这样一个事情：
从i跳每次贪心跳到j
同理从j每次贪心跳到i
然后，计算路径编号和sum1,sum2
sum1-sum2=1，这就是必要条件 
我觉得是充分的啊
确实是 
好麻烦感觉我靠
 
*/
