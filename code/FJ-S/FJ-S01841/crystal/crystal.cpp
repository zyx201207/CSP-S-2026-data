#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500024],ans,s[500024];
bool f(long long v){
	long long x=1,y=2,sum=0;
	while(y<=n&&x<=y){
		if(y-x>=v)return 1;
		if(sum+s[y]*(y-1)<=m){
			sum+=s[y]*(y-1);
			y++;
		}else{
			sum-=s[x+1]*x;
			x++;
		}
	}if(y-x>=v&&sum<=m)return 1;
	else return 0;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)s[i]=a[i]-a[i-1];
	long long l=1,r=n;
	while(l<=r){
		long long mid=(r-l)/2+l;
		if(f(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}cout<<ans<<endl;
	return 0;
}
