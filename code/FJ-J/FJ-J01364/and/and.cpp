#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],aum,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i =1;i<=n;i++)
		cin>>a[i];
	if(m==2){
		for(long long b = 1;b<=n;b++){
			for(long long c=b+1;c<=n;c++){
				aum=a[b]&a[c];
				ans=max(ans,aum);
			}
		}
	}
	if(m==3){
		for(long long b = 1;b<=n;b++){
			for(long long c=b+1;c<=n;c++){
				for(long long d=c+1;d<=n;d++){
					aum=a[b]&a[c]&a[d];
					ans=max(ans,aum);	
				}
			}
		}
	}
	if(m==4){
		for(long long b = 1;b<=n;b++){
			for(long long c=b+1;c<=n;c++){
				for(long long d=c+1;d<=n;d++){
					for(long long e=d+1;e<=n;e++){
						aum=a[b]&a[c]&a[d]&a[e];
						ans=max(ans,aum);		
					}
				}
			}
		}
	}
	if(m==5){
		for(long long b = 1;b<=n;b++){
			for(long long c=b+1;c<=n;c++){
				for(long long d=c+1;d<=n;d++){
					for(long long e=d+1;e<=n;e++){
						for(long long f=e+1;f<=n;f++){
							aum=a[b]&a[c]&a[d]&a[e]&a[f];
							ans=max(ans,aum);		
						}	
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
