#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}
	else if(m==n){
		for(long long i=1;i<=n;i++){
			ans=a[i]&a[i+1];
		}
		cout<<ans;
	}
	else if(m==2){
		long long maxx=0;
		for(long long i=1;i<=n;i++){
			int f=0;
			for(long long j=1;j<=n;j++){
				if(i==j){
					f=1;
					continue;
				}
				ans=a[i]&a[j];
				maxx=max(ans,maxx);
			}
		}
		cout<<maxx;
	}
	return 0;
} 
