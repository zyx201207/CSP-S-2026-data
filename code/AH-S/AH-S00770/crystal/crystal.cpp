#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],s[500005],ans=INT_MIN; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		f[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		s[i]=1;
		long long z=m; 
		for(int j=i;j<n;j++){
			if(f[j+1]*(j-i+1)<=z){
				s[i]++;
				z-=f[j+1]*(j-i+1);
			}else{
				j=n;
			}
		}
	}
	for(int i=1;i<n;i++){
		ans=max(ans,s[i]);
	}
	cout<<ans;
	return 0;
}

