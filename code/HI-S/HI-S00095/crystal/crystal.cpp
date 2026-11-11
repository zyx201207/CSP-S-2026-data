#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-10000;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long nowm=m,ans=0;
		for(long long j=i-1;j>=1;j--){
			
			if(nowm-(a[i]-a[j])>=0) {
				ans++;
				//cout<<a[j]<<' ';
				nowm=nowm+a[j]-a[i];
			} 
			
		}
		//cout<<endl;
		maxx=max(maxx,ans+1);
	}
	cout<<maxx;
	return 0;
}

