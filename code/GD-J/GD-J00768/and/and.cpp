#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	wfreopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
