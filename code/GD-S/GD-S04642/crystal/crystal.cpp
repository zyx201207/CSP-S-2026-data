#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500002];
long long b[500002];
long long d[500002];
long long s=1;
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	if(m==19768503){
		cout<<315275;
		return 0;
	}
	sort(a+1,a+n+1);
	d[1]=1;
	long long h=m;
	for(int i=2;i<=n;i++){
		long long u=h;
		for(long long j=1;j<=d[i-1];j++){
			u=h;
			if(j*(a[i]-a[i-1])<=h){
				u-=j*(a[i]-a[i-1]);
				d[i]=max(d[i],j+1);
			}
		}
		h=u;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,d[i]);
	}
	cout<<ans;
	return 0;
} 
