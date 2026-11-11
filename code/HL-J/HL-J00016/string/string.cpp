#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
long long s[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	long long r=s[n];
	int rl=n-1;
	for(int i=1;i<=n;i++){
		long long k=s[n]-s[i]+1;
		if(k<=s[n]/2) break;
//		cout<<k<<" ";
		if(c[rl+1]!=c[i]){
			ans+=r-s[rl];
		}
		rl--;
		for(;s[rl]>=k;rl--){
			if(c[rl+1]!=c[i]){
				ans+=s[rl+1]-s[rl];
			}
		}
		if(c[rl+1]!=c[i]){
			ans+=s[rl+1]-k+1;
		}
		r=k-1;
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}