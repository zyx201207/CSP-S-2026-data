#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
long long ans=-1;
bool fg;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cha=a[2]-a[1];
	for(long long i=1;i<=n-1;i++){
		if(a[i+1]-a[i]!=cha){
			fg=1;
			break;
		}
	}
	if(fg){
		long long s=0,sum=0,pianyi=0;
		for(long long i=1;i<=n;i++){
			sum=0;
			s=0;
			for(long long j=i;j>=1;j--){
				sum+=a[i]-a[j];
				if(sum>m){
					break;
				}
				s++;
			}
			
			ans=max(ans,s);
		}
		cout<<ans;
	}else{
		cout<<n*cha/2;
	}
	return 0;
}
