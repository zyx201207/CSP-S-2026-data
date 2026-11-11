#include<bits/stdc++.h>
using namespace std;
#define int long long
#define file(S) freopen(S".in","r",stdin),freopen(S".out","w",stdout);
const int N=2e6+10;
int a[N],hf[N],sum1[N],sum2[N];
int n,d;
bool check(int i,int x)
{
	if(x<1) return 1;
	if(sum1[i]-sum1[x+2]==1&&sum2[i]-sum2[x+2]==1) return 1;
	return 0;
}
void Luo_Saisei() {
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		hf[i]=0;
		sum1[i]=sum2[i]=0;
	}
	a[n+1]=4e18;
	a[0]=-4e18;
	for(int i=1;i<=n-3;i++)
	{
		int r=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		if(r-i+1>3) continue;
		if(r<n&&a[r+1]-a[r]>d) continue;
		hf[r+1]=1;//hf_r 到hf_r-3 都是合法序列 
		//接下来就是计数了 我们考虑左端点的长度Li和Ri sigma一下就是答案了
		//Li 和Ri受到断点限制 
		//做两个前缀和 sum1=1表示区间有1一个合法 sum2=1 表示区间断点和合法加起来有1个 
		//sum1=sum2=1 
	}
	for(int i=1;i<=n;i++)
	{
		sum1[i]+=sum1[i-1]+hf[i];
		sum2[i]+=sum2[i-1]+hf[i];
		if(i>=2) sum2[i]+=((a[i]-a[i-1])>d);
//		cout<<sum1[i]<<' '<<sum2[i]<<'\n';
	}
	int Ans=0;
	for(int i=4;i<=n;i++)//考虑二分出一个最长的前缀 
	{
		int l=1,r=i-3,ans1=-1,ans2=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(i,mid)) ans1=mid,r=mid-1;
			else l=mid+1;	
		}	
		if(ans1==-1) continue;
		l=ans1,r=i-3;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(i,mid)) ans2=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans1==-1||ans2==-1) continue; 
//		cout<<ans2<<' '<<ans1<<'\n';
		Ans+=ans2-ans1+1;
	} 
	cout<<Ans<<'\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	file("migrate");
	int c,T=1;
	cin>>c>>T;
	while(T--) Luo_Saisei();
}
//我怎么 好像会了 16:36
//先考虑不存在点对的序列 如果 L二分出的R之间只有一个点 那自然合法  
//那我们不妨考虑特殊点对p u x y v q
// 你看这是不是很像差分约束 
//我们考虑往外拓展  
//  
