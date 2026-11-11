#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		int n,m,maxn =0,ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=n;i>=n-m;i--){
			for(int j=1;j<=m;j++)
				ans = ans&&a[i];
			maxn=max(maxn,ans);
		}
		cout<<a[n-m];
	return 0;
}
