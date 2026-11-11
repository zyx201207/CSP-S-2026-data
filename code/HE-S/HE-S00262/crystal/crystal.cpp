#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],pre[500010],ans;
bool ok(int l,int r){
	return (a[r]*(r-l+1)-pre[r]+pre[l-1])<=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i]; 
	}	
	for(int i=1;i<=n;i++){
		int l=i,r=n,x=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(ok(i,mid)){
				l=mid+1;
				x=mid;
			}
			else{
				r=mid-1;
			}
		}
//		cout<<i<<" "<<x<<" "<<a[x]*(x-i+1)-pre[x]+pre[i-1]<<"\n"; 
		ans=max(ans,x-i+1); 
	}
	cout<<ans;
	return 0;
}







/*

Oct31==Dec25?

luogu.com.cn/user/1006815   stem12345xi
luogu.com.cn/user/忘了      xiguan1 

florr.io   xiguan1
zorr.pro   xiguan1 

上午AK失败
不管了 

巧克力好吃 

14:35开始看题 

14:52写完T1 
14:53成功没过样例 

15:01调对了 
15:03大样例3没过
15:04发现没sort 
15:06大样例过了 
*/
