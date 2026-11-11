#include <bits/stdc++.h>
using namespace std;
int n,x,y,ans;
long long a[500001],b[500001],m,sum;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	x=1,y=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[1],ans=1;
	while(y<=n){
//		cout<<x<<" "<<y<<" "<<(y-x+1)*a[y]<<" "<<sum<<"\n";
		y++;
		sum+=a[y];
		if((y-x+1)*a[y]-sum<=m)ans=max(ans,y-x+1);
		else while((y-x+1)*a[y]-sum>m){
			x++;
			sum-=a[x];
		}
	}
	cout<<ans;
	return 0;
}
