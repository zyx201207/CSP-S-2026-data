#include<bits/stdc++.h>
using namespace std;
#define int long long 


const int N=5e5+10;
int n,m;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1,j=1,now=m;
	for(int i=1;i<=n;i++){
		while((i-j)*(a[i]-a[i-1])>now)now+=a[i-1]-a[j],j++;
		now-=(i-j)*(a[i]-a[i-1]);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
	
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
/*
给定 n 个有权值的数
每次可以选一个数 +1
有最多 m 次机会
问最多能使多少个数相同 

 
*/
