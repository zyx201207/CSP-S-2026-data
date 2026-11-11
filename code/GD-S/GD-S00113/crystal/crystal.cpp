#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qa[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qa[i]=qa[i-1]+a[i];
	for(long long i=1,j=1;i<=n;i++){
		while(j<=n&&(j-i+1)*a[j]-(qa[j]-qa[i-1])<=m){
			ans=max(ans,j-i+1);
			j++;
		}
		if(j>n)break;
	}
	cout<<ans;
	return 0;
}
