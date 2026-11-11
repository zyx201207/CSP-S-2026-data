//遵义市第四中学 陈文涛 GZ-S00213 
#include <bits/stdc++.h>
using namespace std;

long long a[600004];
long long b[600004];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]*i;
		a[i]+=a[i-1];
	} 
	for(int i=1;i<=n;i++){
		if(m>=b[i]-a[i]) ans++;
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


