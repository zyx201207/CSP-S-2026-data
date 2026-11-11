#include<bits/stdc++.h>
using namespace std;
const int dd=2e5+5;
int n;
struct st{
	long long x;
	char c;
}a[dd];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		long long k=min(a[l].x,a[r].x)*1ll;
		a[l].x-=k;
		a[r].x-=k;
		if(a[l].c!=a[r].c) ans+=k;
		if(a[l].x==0) l++;
		if(a[r].x==0) r--;
	}
	cout<<ans;
	return 0;
}
