#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+1];
	char c[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0,b=1,e=n;
	for(long long i=1;i<=n;i++){
		if(c[b]!=c[e]){
			int d=min(a[b],a[e]);
			ans+=d;
			a[b]-=d;
			a[e]-=d;
			if(a[b]==0){
				b+=1;
			}
			if(a[e]==0){
				e-=1;
			}
		}
		else{
			int d=min(a[b],a[e]);	
			a[b]-=d;
			a[e]-=d;
			if(a[b]==0){
				b+=1;
			}
			if(a[e]==0){
				e-=1;
			}
		}
		if(b==e){
			break;
		}
	}
	cout<<ans;
	return 0;
}
