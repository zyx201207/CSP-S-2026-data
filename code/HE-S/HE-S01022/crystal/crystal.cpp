#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500010];
long long d[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(((a[i]-a[i-1])*i-1)<=m){
			m-=((a[i]-a[i-1])*i-1);
			d[1]+=(a[i]-a[i-1]);
			d[i-1]-=(a[i]-a[i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+d[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
