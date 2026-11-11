#include <bits/stdc++.h>
using namespace std;
long long a[500010],n,m,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		
	}sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long ans=0;
		for(long long j=i;j>=1;j--){
			ans+=a[i]-a[j];
			if(ans<=m){
				if(i-j+1>maxx){
					maxx=i-j+1;
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
