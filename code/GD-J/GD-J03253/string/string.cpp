#include<iostream>
#define int long long
using namespace std;
int a[200005],n,ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			a[l]-=a[r];
			ans+=a[r]*(c[r]!=c[l]);
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			ans+=a[l]*(c[r]!=c[l]);
			l++;
		}
		else ans+=a[l]*(c[l]!=c[r]),l++,r--;
	}
	cout<<ans;
	return 0;
}
