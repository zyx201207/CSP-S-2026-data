#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b=1,e=0,f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			e=1;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2] && i>2){
			f=1;
		}
	}
	sort(a+1,a+n+1);
	if(e==0){
		long long o=0;
		for(long long i=1;i<=n;i++){
			if(o+a[i-1]<=m){
				o+=a[i-1];
			}else{
				b=max(i-1,b);
				break;
			}
			if(i==n){
				b=n;
			}
		}
	}else if(f==0){
		long long o=a[2]-a[1];
		double u=0;
		for(long long i=n;i>=1;i--){
			u=(a[i]-a[1]+o)*1.0*(i-1)/2.0;
			if(u>int(u)){
				u+=int(u)+1;
			}else{
				u=int(u);
			}
			if(u<=m){
				b=i;
				break;
			}
		}
	}else{
		for(long long i=n;i>=1;i--){
			long long o=0,u=1;
			for(long long j=i-1;j>=1;j--){
				if(o+a[i]-a[j]<=m){
					u++;
					o+=a[i]-a[j];
				}else{
					break;
				}
			}
			b=max(b,u);
			if(b>=i){
				break;
			}
		}
	}
	cout<<b;
	return 0;
}
