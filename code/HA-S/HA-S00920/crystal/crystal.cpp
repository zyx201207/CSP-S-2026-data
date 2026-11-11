#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500004],l,r,u,c=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	while(r<n-1){
		r++,u+=(a[r]-a[r-1])*(r-l);
		while(u>m)u-=(a[r]-a[l]),l++;
		c=max(r-l+1,c);
	}cout<<c;
	return 0;
}
