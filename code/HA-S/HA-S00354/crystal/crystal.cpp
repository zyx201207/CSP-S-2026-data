#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],l=1,s[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for (ll i=2;i<=n;i++){
		if(m>=(i-l+1)*a[i]-(s[i]-s[l-1])){
			ans=max(ans,i-l+1);
		}else{
			while(m<(i-l+1)*a[i]-(s[i]-s[l-1])&&l<=i){
				l++;	
			}
		}
	}cout<<ans;
	return 0;
} 
