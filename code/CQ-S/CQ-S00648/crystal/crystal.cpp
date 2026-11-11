#include<bits/stdc++.h>
#define online
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
ll a[500005],qz[500005];
int ans;
int main(){
#ifdef online
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,val=0;
		while(l<=r){
			int mid=l+r>>1;//mid~i-1,总共i-mid个数字 
			if(a[i]*(i-mid)-(qz[i-1]-qz[mid-1])<=m){//可行 
				val=i-mid;r=mid-1;
			}else l=mid+1;
		}ans=max(ans,val+1);
	}cout<<ans;
	
	return 0;
}
/*d 
感觉T1比较简单，进 T2，看了题再说 

OK，T2看完了，这个T1感觉像是..做过的？要尽可能全部变成一样的

贪心啊，DP有可能但不大

m 次+1操作 

肯定不能浪费，每次+1都是为了抹平而加的，不能加了wyy，而且“至多”

非常好。

排序不影响，先排序。

然后：作为“最大”（也就是你选定的那个作为相等值） 必然是输入中的一个数字 a_i

可以枚举，然后二分，然后做完了

我天什么**题 
---
细节：随便你怎么枚举，求区间和就是。必然是 

可以负数不影响。就是值域有点大，还好，5e5*1e12=5e17，在m范围以内 

14:47 轻松拿下 

回来了，14:51，发现m没开long long，差点AFO

数据太弱了，居然没检测出来 

感觉BS机子不是很强啊，怎么啥都没有都要运行0.2s？hyw. 
*/
