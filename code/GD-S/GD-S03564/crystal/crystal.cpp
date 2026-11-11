#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+10;
ll n,m,a[N],b[N],ans,sum[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		sum[i]=b[i-1]*(i-1)+sum[i-1];
		if(sum[i]<=m) ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
