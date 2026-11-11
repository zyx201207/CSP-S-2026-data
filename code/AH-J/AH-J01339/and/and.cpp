#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long c[200005];
bool b[200005];
long long n,m;
long long mx;
inline void d(int x){
	if(x==m+1){
		long long ans=c[1];
		for(long long i=1;i<=m;i++){
			ans&=c[i];
		}
		mx=max(mx,ans);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]>=c[x-1] and !b[i]){
			c[x]=a[i];
			b[i]=1;
			d(x+1);
			b[i]=0;
		}
	}
}
bool f(int x){
	x++;
	while(x){
		if(x%2==0) x/=2;
		else return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(long long i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long ans=0;
		for(long long i=1;i<=n;i++){
			long long cnt=a[1];
			if(i==1) cnt=a[2];
			for(int j=1;j<=n;j++){
				if(j==1) continue;
				cnt&=a[j];
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		if(f(a[i])) cnt++;
	}
	if(cnt==n){
		cout<<a[n-m+1];
		return 0;
	}
	cnt=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==i-1) cnt++;
	}
	if(cnt==n){
		long long cnt2=a[n-m+1];
		for(long long i=n-m+1;i<=n;i++){
			cnt2&=a[i];
		}
		cout<<cnt2<<endl;
		return 0;
	}
	mx=0;
	d(1);
	cout<<mx;
	return 0;
}
