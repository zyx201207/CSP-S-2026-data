//GZ-S00364 遵义市第四中学 隆银艳
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int cha=a[2]-a[1];
		cout<<n%(d/cha*2)+1;
	}

	return 0;
}
