#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn];
long long k[maxn],z[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	k[0]=z[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		k[i]=a[i]-a[i-1];
		z[i]=z[i-1]+k[i];
		//cout<<k[i]<<" "<<z[i]<<"\n";
	}
	sort(a+1,a+1+n);
	long long l=0;
	long long sum=0,ans=0;
	for(long long r=1;r<=n;r++){
		sum+=(r-l-1)*k[r]*1LL;
		//cout<<l<<" "<<r<<" "<<sum<<"\n ";
		while(sum>m&&l<r){
			l++;
			sum-=(z[r]-z[l-1]);
		}
		ans=max(ans,(r-l));
	}
	cout<<ans;
	return 0;
}
