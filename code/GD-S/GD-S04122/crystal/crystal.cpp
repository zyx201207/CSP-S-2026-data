#include <bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m;
long long a[N];
long long f[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=(a[i+1]-a[i])*i+f[i-1];
	}
	//sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(f[i]-f[j]-(j-1)*(a[i]-a[j])<=m) ans=max(ans,i-j);
			else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
