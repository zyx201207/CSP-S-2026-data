#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	long long maxx=-1; 
	for(int i=n;i>=1;i--){
		long long r=i-1,ans=0,x=m;
		while(x>=0&&r>=0){
			ans++;
			x-=abs(a[i]-a[r]);
			r--;
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 
