#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,cnt;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[0]=0;
	for(long long i=1,io=1;i<=n;i++){
		if(a[i]==a[i-1]){
			b[i]=b[i-1];
			io++;
		}
		else{
			b[i]=b[i-1]+(a[i]-a[i-1])*(io-1);
			io++;
		}
	}
	long long ans=0;
	b[n+1]=LONG_LONG_MAX;
	for(long long i=1;i<=n;i++){
		long long Num=b[i]+m;
		long long id=0;
		id=upper_bound(b+1,b+1+n,Num)-b;
		id--;
		ans=max(ans,id-i+1);
	}
	cout<<ans;
	return 0;
}
