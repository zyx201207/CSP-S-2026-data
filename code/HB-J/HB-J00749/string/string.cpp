#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],b[200010];
ll ans;
string c[200010],d[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	int l=1,r=1;
	while(l<=n&&r<=n){
		//cout<<l<<" "<<r<<" "<<a[l]<<" "<<b[r]<<" ";
		if(a[l]<b[r]){
			if(c[l]!=d[r]) ans+=a[l];
			b[r]-=a[l];
			l++;
		}
		else if(a[l]>b[r]){
			if(c[l]!=d[r]) ans+=b[r];
			a[l]-=b[r];
			r++;
		}
		else{
			if(c[l]!=d[r]) ans+=a[l];
			a[l]=b[r]=0;
			l++;
			r++;
		}
		//cout<<ans<<"\n";
	}
	cout<<ans/2;
	return 0;
}
