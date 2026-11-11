#include<bits/stdc++.h>
using namespace std;
long long a[50000005];
struct node{
	long long sum;
	long long chan;
} b[50000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long mx=-1000000005,mn=1000000005;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		mn=min(a[i],mn);
	}
	if(n>5000){
		long long i=a[1]-a[0],ans=1,x=a[1]-a[0];
		while(i<=m){
			m-=x;
			x+=i;
			ans++;
		}
		cout<<ans;
	}else{
		sort(a,a+n);
		for(long long i=mn;i<=mx;i++){
			long long cnt=0,sm=0;
			for(long long j=0;j<n;j++){
				if(i>=a[j]){
					cnt+=(i-a[j]);
					sm++;
				}else{
					break;
				}
			}
			if(cnt<=m){
				b[i+100005].chan =cnt;
				b[i+100005].sum =sm;
			}else{
				break;
			}
		}
		long long ans=0;
		for(long long i=mn;i<=mx;i++){
			ans=max(ans,b[i+100005].sum );
		}
		cout<<ans;		
	}
	return 0;
} 
