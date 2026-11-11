#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int si=5e5+10;
int n,ans=1;
ll m,a[si],c[si];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)/2;
			ll ch=i-mid+1;
			if(ch*a[i]-(c[i]-c[mid-1])<=m)
				r=mid;
			else l=mid;
		}ans=max(ans,i-r+1);
	}printf("%d",ans);
	return 0;
}
/*
14:05吓哭了忘记带身份证了
14:20还好进来了呜呜呜吓哭了 
14:26上善若水 
14:27 Oct31==Dec25? 
14:28不行了太好笑了哈哈哈 
14:29 X X XXX || X X XXX
14:40想到思路了写T1中 
14:47 T1水题样例全过，体感橙题 
14:50应该没什么问题了 
18:16求求了不要爆零啊 
*/
