#include<bits/stdc++.h>
using namespace std;
long long f[500005],a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,l=1,r,ans=-1,t=1;
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(t&&i>=3&&f[i]-f[i-1]!=f[i-1]-f[i-2]){
			t=0;
		}
	}if(t&&n>=3){
		int k=f[2]-f[1];
		for(long long i=k;i<n*k;i+=k){
			if(m>=i){
				m-=i;
			}else{
				cout<<i/k;
				return 0;
			}
		}cout<<n;
		return 0;
	}
	sort(f+1,f+n+1);
	for(int mid=1;mid<=n;mid++){
		long long l=0,c=1;
		for(int i=mid-1;i>=1;i--){
			l+=f[mid]-f[i];
			if(l<=m){
				c++;
			}
		}ans=max(ans,c);
	}cout<<ans;
	return 0;
} 
