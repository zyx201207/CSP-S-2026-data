#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N],b[N];
long long n,m;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=1;
	int c=n;
	for(int i=1;i<=c;i++){
		for(int j=i;j<n;j++){
			b[j+1]=b[j]+(a[j+1]-a[j])*(j-i+1);
			if(b[j+1]>m){
				ans=max(ans,1ll*(j-i+1));
				c=n-ans;
				break;
			}
			b[j]=0;
			
		}
		b[n]=0;
		
	}
	cout<<ans;
	
	return 0;
}
