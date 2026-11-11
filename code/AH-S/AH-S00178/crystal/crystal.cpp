#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		long long ans=1,m1=m;
		for(long long j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]){
				ans++;
				m1-=(a[i]-a[j]);
			}else{
				break;
			}
		}
		if(ans>maxx){
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
