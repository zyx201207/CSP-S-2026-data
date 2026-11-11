#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],e,l,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		e+=(a[i]-a[i-1])*(i-l);
		if(e>m){
			while(e>m){
				e-=(a[i]-a[++l]);
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

