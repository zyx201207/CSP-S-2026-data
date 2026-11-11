#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000000];
int s[1000000],c[1000000],t[1000000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		c[i]=a[i]-a[i-1];
		t[i]=t[i-1]+(i-1)*c[i];
	}
	int i=1,j=1,ans=0;
	while(i<=n){
		if(t[j]-(i-1)*a[j]+s[i-1]<=m){
			//printf("%lld %lld\n",i,j);
			ans=max(ans,j-i+1);
			if(j==n){
				break;
			}
			j++;
		}
		else{
			i++;
		}
			
	}
	cout<<ans;
}
