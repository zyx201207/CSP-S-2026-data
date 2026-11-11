#include<bits/stdc++.h>
using namespace std;

int n;
long long a[500010],sum[500010],m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) sum[i]=sum[i-1]+a[i]; 
	int maxn=0;
	for(int i = 1,j = 1;i <= n;i++){
		while(j<i&&a[i]*(i-j+1)-(sum[i]-sum[j-1])>m) j++;
		maxn=max(maxn,i-j+1);
	}
	cout<<maxn<<'\n';
	return 0;
}
