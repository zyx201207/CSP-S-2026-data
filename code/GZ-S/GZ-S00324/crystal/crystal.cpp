//GZ-S00324 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long m; 
long long a[500000+50];
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int bei=1;
	for(long long i=2;i<=n;i++){
		if((a[i]-a[i-1])*bei<=m){
			ans++;
			m-=(a[i]-a[i-1])*bei;
			bei++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
