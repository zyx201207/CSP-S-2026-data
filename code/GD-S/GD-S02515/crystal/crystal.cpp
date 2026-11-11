#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,cc=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mm=m;
	for(long long i=n;i>=1;i--){
		m=mm;
		for(long long j=1;j<=i;j++){
			if(a[i]-a[i-j]>m)break;
			b[i]++;
			m-=a[i]-a[i-j];
		}
	}
	long long ma=0;
	for(long long i=1;i<=n;i++){
		ma=max(ma,b[i]);
	}
	if(ma<n)ma+=1;
	cout<<ma<<endl;
	return 0;
}
