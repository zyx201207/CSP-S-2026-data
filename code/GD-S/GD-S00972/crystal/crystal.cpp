#include<bits/stdc++.h>
using namespace std;
long long n,m,sum[500050];
int ans;
long long a[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long need=0;
	for(int i=1,j=1;i<=n;i++){
		need+=(a[i]-a[i-1])*(i-j);
		while(need>m){
			need-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
