#include <bits/stdc++.h> 
using namespace std;
	long long n,m;
	long long a[1000000],b[1000000],s[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		s[i]=s[i-1]+b[i];
	}
	long long l=1,r=1;
	long long ans=0;
	while(r<=n){
		if(s[r]-s[l]<=m){
			ans=max(r-l+1,ans);
			r++;
		}else{
			l++;
			if(l==r){
				r++;
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}
