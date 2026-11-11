#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,a[N],m,sum[N],l=1,r=1,ans=0,maxx=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	while(r<=n){
		while(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m&&r<=n){
			maxx=max(maxx,r-l+1);
			r++;
		}
		l++;
	}
	cout<<maxx<<"\n";
	return 0;
}