#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int l=1,r=1,ans=0;
	long long x=0,y=0;
	while(r<=n&&l<=n){
		if(x<=m){
			ans=max(ans,r-l+1);
			r++;
			x+=(r-l)*b[r];
			y+=b[r];
		}
		else if(x>m){
			y-=b[l];
			x-=y;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
