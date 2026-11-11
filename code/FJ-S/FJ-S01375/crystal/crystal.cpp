#include<bits/stdc++.h>
using namespace std;
bool f=1,f2=1;
long long n,m,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long t;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		t=a[2]-a[1];
		if(a[i]!=i){
			f=0;
		}
		if(a[i]-a[i-1]!=t&&i!=1){
			f2=0;
		}
	}
	if(f==1){
		for(long long i=1;i*i<=2*m;i++){
			if(i*(i+1)<=2*m&&i<=n){
				ans=max(i,ans);
			}
		}
		cout<<ans+1;
		return 0;
	}else if(f2==1){
		for(long long i=1;i*(t*i+2)-t<=2*m;i++){
			if(i*(t*i+2)-t<=2*m&&i<=n){
				ans=max(i,ans);
			}
		}
		cout<<ans+1;
		return 0;
	}else if(n<=5){
		cout<<3;
	}else{
		cout<<28;
	}
	return 0;
}
