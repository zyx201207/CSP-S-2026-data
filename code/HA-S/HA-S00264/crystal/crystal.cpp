#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);bool fb=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			fb=0;
			break;
		}
	}long long sum=0;
	if(fb){
		for(int i=1;i<=n;i++){
			sum+=(1ll)*(a[i]-a[i-1])*(i-1);
			if(sum>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	
	long long maxsum=-1e12;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			sum+=(1ll)*(a[j]-a[j-1])*(j-i);
			if(sum>m){
				maxsum=max(maxsum,(1ll)*j-i);
				break;
			}
		}
		//cout<<a[i]<<" ";
	}
	cout<<maxsum;
	return 0;
}
