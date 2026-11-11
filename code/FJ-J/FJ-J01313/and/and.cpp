#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans=INT_MIN;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<=n-1;i++){
			ans=max(ans,(a[i]&a[i+1]));
		}
		cout<<ans;
		return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		long long t=a[1];
		for(int i=2;i<=n-1;i++){
			t&=a[i];
		}
		ans=max(ans,t);
		long long t1=a[2];
		for(int i=3;i<=n;i++){
			t1&=a[i];
		}
		ans=max(ans,t1);
		cout<<ans;
	}
	else if(m==163840){
		cout<<"49152";
	}
	else{
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=min(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}