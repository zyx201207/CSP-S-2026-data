#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, a[2000025], lst[200005], sum[200005];
vector<pair<int, int> > vc;
signed main(){
//	freopen("aaa.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		vc.clear();
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			lst[i]=sum[i]=0;
			cin >> a[i];
		}
		a[n+1]=a[n+2]=a[n+3]=a[n+4]=LLONG_MAX;
		for(int i=1;i<=n-2;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i]>d){
				if(a[i+3]-a[i+1]<=d&&a[i+4]-a[i+1]>d){
					vc.push_back({i, i+2});
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]>d){
				sum[i]=sum[i-1]+1;
			}else{
				sum[i]=1;
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i]-a[i-1]<=d&&a[i]-a[i-2]>d){
				lst[i]=lst[i+1]+1;
			}else{
				lst[i]=1;
			}
		}
		int ans=0;
		for(int i=0;i<vc.size();i++){
			int x=vc[i].first, y=vc[i].second;
			ans+=sum[x]*lst[y+1];
		}
		cout << ans << endl;
	}
	return 0;
}
/*
如果是等差数列 说明向后跳的方案数相同 
什么算恰好有两条？则说明不同的位置只有一个
则说明在一段距离为d的段里面有三个点且下一个段也满足 而其他只有两个点
如果当前包含了三个点则让f=1然后去看下一个是否也是三个点
如果下一次不是三个点就当经过了一次两个点算 
如果是两个点则让计数的加1 要注意加的是哪边的
如果遇到了包含四个点或1一个点则说明断开了 ans+=num1*num2 num1=0, num2=0 
*/
