#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=5e5+10;
ull m,cnt=0,ans=1;
ll n,a[N],count[N];
ull s[N]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%llu",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
	}
	ll i=n,j=n-1;
	while(i>=1&&j>=0){
		while(cnt<=m){
			cnt+=a[i]-a[j];
			if(j>=0)j--;
			else break;
		}
		ans=max(ans,(unsigned long long)(i-j-1)); 
		while(cnt>m){
			cnt-=(i-j-1)*s[i-1];
			i--;
			if(i<1){
				break;
			}
			if(i==j){
				cnt=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
