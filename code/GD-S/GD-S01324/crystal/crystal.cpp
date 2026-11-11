#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long x=1,y=0;
	for(long long i=1;i<=n;i++){
		y+=(i-x)*(a[i]-a[i-1]);
		while(x<i&&y>m){
			y-=a[i]-a[x];
			x++;
		}
		ans=max(ans,i-x+1);
	}
	cout<<ans;
	return 0;
}
