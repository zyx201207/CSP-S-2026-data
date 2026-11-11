//bl
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[510001],s[5100001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll ans=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]*(j-i+1)-s[j]+s[i-1]<=m){
				ans=max(ans,j-i+1);
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

