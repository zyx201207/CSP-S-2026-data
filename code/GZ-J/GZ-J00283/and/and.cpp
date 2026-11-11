//GZ-J00283 赵宸泽 贵阳市观山湖区第一高级中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n;i>=n-m+1;i--)
		ans&=a[i];
	cout<<ans;
	return 0;
}
