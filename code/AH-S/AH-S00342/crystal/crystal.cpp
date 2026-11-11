#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],f[500005],w[500005],d,maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for (ll i=1;i<=n;i++)	cin >>a[i];
	sort(a+1,a+n+1);
	f[1]=1;w[1]=0;maxx=1;
	for (ll i=2;i<=n;i++){
		d=a[i]-a[i-1];
		f[i]=f[i-1]+1;
		w[i]=w[i-1]+d*f[i-1];
		while(w[i]>m&&f[i]>1){
			w[i]=w[i]-(a[i]-a[i-f[i]+1]);
			f[i]--;
		}
		maxx=max(maxx,f[i]);
	}
	cout <<maxx<<endl;
	return 0;
}
