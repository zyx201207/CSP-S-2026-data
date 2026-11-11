#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ans;
long long a[N],f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int j=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
		while(f[i]-f[j]-(j-1)*(a[i]-a[j])>m&&j<i) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}