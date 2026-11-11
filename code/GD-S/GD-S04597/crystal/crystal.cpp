#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=1,ans,hh;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=2;i<=n;i++){
		ans=a[2]-a[1];
		if(a[i]-a[i-1]!=ans){
			hh=1;
		}
	}if(!hh){
		m/=ans;
		long long yuan=0;
		for(int i=1;i<=n;i++){
			yuan+=i;
			if(yuan>m){
				cout<<i;
				return 0;
			}
		}cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	long long sum=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j>=1;j--){
			if(sum+a[i]-a[j]>m){
				maxx=max(maxx,j);
				break;
			}
			sum+=a[i]-a[j];
		}if(sum<=m){
			maxx=max(maxx,i);
		}
	}cout<<maxx;
	return 0;
} 
