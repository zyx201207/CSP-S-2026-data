#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n,l,r,ans;
long long a[N],pre[N];
long long m,sum,m1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	l=1;
	for(int r=1;r<=n;r++){
		sum=1ll*(r-l+1)*a[r];
		m1=pre[r]-pre[l-1];
		while(sum-m1>m&&l<r){
			l++;
			sum=1ll*(r-l+1)*a[r];
			m1=pre[r]-pre[l-1];
		}
		ans=max(ans,(r-l+1));
	}
	cout<<ans;
	return 0;
} 
