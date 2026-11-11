#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
bool ok(long long x){
	
	for(int l=1;l+x-1<=n;l++){
		int r=l+x-1;
		long long keyi=a[r]*x;
		if(keyi-(s[r]-s[l-1])<=m)return 1;
	}
	return 0;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n,ans=0;
	while(l<=r){
		long long k=(l+r)/2;
		if(ok(k)){
			ans=k;
			l=k+1;
		}else{
			r=k-1;
		}
	}
	cout<<ans;
	return 0; 
}
