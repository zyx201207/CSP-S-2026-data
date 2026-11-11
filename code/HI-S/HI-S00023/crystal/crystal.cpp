#include<bits/stdc++.h>
using namespace std;
/*
有个贪心 排序后我们最优的选择绝对是一个包含目标数的区间 
考虑排序 因为调整只能往上调 
我们注意到 如果从1~n开始枚举 前面数的调整为i代价是前面的数调整为i-1的代价*(i-(i-1)+(i-(i-1) 这是一个可以复用的差分
并且上面的式子一定单调不降 考虑双指针 
维护窗口长度以及修改花费 
*/
const int N=5*1e5+5;
long long n,m,a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	int l=1,ans=1;long long p=0;
	for(int r=1;r<=n;r++){
		p+=(r-l)*(a[r]-a[r-1]); 	
		while(l<r&&p>m){
			p-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n"; 
	return 0;
}
