#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N],c[N],d[N],e[N],n,m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		c[i]=b[i]+c[i-1];
	}
	for(int i=1;i<n;i++){
		e[i]=c[i]+e[i-1];
	}
	for(int i=1;i<n;i++){
		d[i]=c[i]*i-e[i];
	}
	for(int i=n-1;i>=1;i--){
		if(d[i]<=m){
			cout<<i+1;
			break;
		}
	}
	return 0;
}
