#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],b[500010],ans=0,l=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	for(int i=2;i<=n;i++){
		while(b[i]-b[l]-(a[i]-a[l])*l>m){
			l++;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
} 
