#include<bits/stdc++.h>
using namespace std;
long long n,m,x,l,a[500005],d=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		x+=(i-l)*(a[i]-a[i-1]);
		while(x>m)x-=a[i]-a[l],l++;
		d=max(d,i-l+1);
	}
	cout<<d;
	return 0;
} 
