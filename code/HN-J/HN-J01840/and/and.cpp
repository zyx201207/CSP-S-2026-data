#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],ans,f[N],mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>n-m;i--){
		long long cnt=0,t=a[i];
		while(t){
			f[++cnt]+=t%2;
			t/=2;
		}
		mx=max(mx,cnt);
	}
	for(int i=mx;i>=1;i--){
		if(f[i]==m){
			ans+=int(pow(2,i-1));
		}
	}
	cout<<ans;
	return 0;
}

