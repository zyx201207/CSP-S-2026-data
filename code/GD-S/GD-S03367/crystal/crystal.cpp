#include<iostream>
#include<algorithm>
using namespace std;
long long a[500003],s[500003],m;
int n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,l,r,mid;i<=n;i++){
		s[i]=s[i-1]+a[i];
		l=1;r=i;
		while(l<r){
			mid=l+r>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]>m)l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
