//GZ-S00264 遵义市第四中学 董云旗 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],q[500001];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[j]-((i-1)*a[j]-q[i-1])<=m){
				ans=max(ans,j-i+1);
			} 
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
