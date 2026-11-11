#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e8+10;
int n,m,maxn=-1;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int sum=0,ans=1;
		for(int j=i-1;j>=1;j--){
			if((sum+a[i]-a[j])<=m){
				sum=sum+a[i]-a[j];
				ans++;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
