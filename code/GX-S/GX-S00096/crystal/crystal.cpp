#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,x,b[500005];
int ans=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(b[i]-b[j]<=m){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
