#include<bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long a[500005];
long long q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	for(long long l=1,r=1;r<=n;r++){
		while(a[r]*(r-l+1)-(q[r]-q[l-1])>m){
			l++;
		}
		mx=max(mx,r-l+1);
	}
	cout<<mx;
	return 0;
}
