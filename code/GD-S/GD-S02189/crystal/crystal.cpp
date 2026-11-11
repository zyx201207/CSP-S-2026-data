#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005],ans=1,sum,minb;
bool f=0;
int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1),minb=b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1],minb=min(minb,b[i]);
		if(a[i]!=a[i-1]) f=1;
	}
	if(f==0){cout<<n;return 0;}
	if(minb>m){cout<<"1";return 0;}
	for(int i=2,j;i<=n;i++){
		sum=0,j=i+1;
		while(j>=1 && 2*sum+b[--j]<=m) sum=2*sum+b[j];
		ans=max(ans,(i-j+1)*1ll);
	}
	cout<<ans;
	return 0;
}
