#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mx=-1;
	for(int i=29;i>=0;i--){
		int num=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i))num++;
		}
		if(num>=m){
			mx=i;break;
		}
	} 
	if(mx==-1){
		cout<<0;
		return 0;
	}
	int ans=(1<<mx);
	for(int i=1;i<=n;i++){
		if(a[i]&(1<<mx))vis[i]=1;
	}
	while(true){
		int pre=mx;
		for(int i=mx-1;i>=0;i--){
			int num=0;
			for(int j=1;j<=n;j++){
				if(!vis[j])continue;
				if(a[j]&(1<<i))num++;
			}
			if(num>=m){
				mx=i;break;
			}
		}
		if(mx==pre)break;
		ans|=(1<<mx);
		for(int i=1;i<=n;i++){
			if(!vis[i])continue; 
			if(a[i]&(1<<mx))vis[i]=1;
			else vis[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
/*
一眼贪心，首先找到最大的有 m 个数的位，

然后容易发现我们一定会选拥有这些位的数，原因显然 

那如果还有多个，那么向下一位进行同样操作，只到没有 

那么时间复杂度O(log val n) 
*/
