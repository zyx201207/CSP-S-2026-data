#include<bits/stdc++.h>
using namespace std;
const int nn=5e5;
long long n,m;
long long a[nn];
long long ans=1,b=1;
unsigned long long tot[nn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	tot[0]=0;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		tot[i]=tot[i-1]+a[i];
	}
	long long l=1,r=2;
	while(r<=n){
		if((r-l)*a[r]-(tot[r-1]-tot[l-1])<=m){
			b++;
			ans=max(ans,b);
			if(l-1==0) r++;
			else l--;
		}
		else{
			r++;
			l=r-1;
			b=0;
		}
	}
	cout<<ans;
	return 0;
}
