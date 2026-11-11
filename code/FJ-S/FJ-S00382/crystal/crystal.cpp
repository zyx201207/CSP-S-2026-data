#include<bits/stdc++.h>
using namespace std;
long long a[500009],cnt,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j=1,ans=1;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++){
		cnt+=((a[i]-a[i-1])*(i-j));
		while(cnt>m&&j<=i){
			cnt-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}