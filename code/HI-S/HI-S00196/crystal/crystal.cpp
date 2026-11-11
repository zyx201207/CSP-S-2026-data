#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&(i-j)*(a[i]-a[i-1])+sum>m){
			sum-=a[i-1]-a[j];
			j++;
		}
		sum+=(i-j)*(a[i]-a[i-1]);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
