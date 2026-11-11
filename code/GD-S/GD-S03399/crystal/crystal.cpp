#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

long long n,m,ans=1,sum[N],a[N];
bool hi(long long x){
	if(a[x]*x-sum[x]>m){return 0;}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){sum[i]=sum[i-1]+a[i];}
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(hi(mid)){l=mid+1;ans=mid;}
		else{r=mid-1;}
	}
	while(a[ans+1]==a[ans]){ans++;}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
