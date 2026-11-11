//GZ-J00261 遵义市第十一中学 夏琮凯  03
#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
}

