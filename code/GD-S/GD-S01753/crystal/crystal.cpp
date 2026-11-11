#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,k=1,ans=0;
	cin>>n>>m;
	if(n<=5001){
	long long a[n+1],b[n+1],c[n+1]={0,0},d[n+1]={1,1};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		for(long long j=k;j<=i;j++){
			long long t=d[j]*b[i]+c[j];
			if(t<=m){
				c[j]+=d[j]*b[i];
				d[j]++;
			}else{
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,d[i]);
	}
	cout<<ans;}else{
		long long s,l;
		cin>>s>>l;
	for(long long i=1;i<=n;i++){
				k+=(l-s)*i;
				if(k>m){
					cout<<i;
					break;
				}
			}
	}
} 
