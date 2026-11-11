#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,sum,ans,a[N],b[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];// 差分数组 
	int h=1,t=0,len=0;
	while(t<n){
		while(t<n && sum+len*b[t]<=m){
			t++;
			sum+=len*b[t-1];
			len++;
			//cout<<sum<<'\n';
		}
		//cout<<h<<" "<<t<<" "<<sum<<'\n';
		ans=max(ans,len);
		//cout<<a[t]-a[h]<<'\n';
		sum-=a[t]-a[h];
		h++;
		len--;
	} 
	cout<<ans;
	return 0;
}
/*
T1
但觉可做性很强啊
贪心的思维
因为只能向上加，所以sort之后。。。

不对，他不一定是以第一个为起点
直接暴力是n方
考虑双指针，维护当前的sum
好像就是一种类似于莫队的写法 
5 5
1 2 4 8 9

完了犯傻了，没sort就差分的来了 
*/
