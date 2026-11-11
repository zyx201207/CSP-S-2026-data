#include<bits/stdc++.h>
#define int long long
#define per(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,y,x) for(int i=y;i>=x;i--)
using namespace std;
int n,sum1,sum2;
struct node{
	int cnt;
	char ch;
}a[200005];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	per(i,1,n) cin>>a[i].cnt>>a[i].ch;
	int x=(n%2==0?n/2:n/2+1);
	per(i,1,x-1) {
		int j=n-i+1;
		sum1+=(a[i].ch==a[j].ch?0:a[i].cnt);
	} 
	per(i,x+1,n) {
		int j=n-i+1;
		sum2+=(a[i].ch==a[j].ch?0:a[i].cnt);
	}
	cout<<max(sum1,sum2);
	return 0;
}
