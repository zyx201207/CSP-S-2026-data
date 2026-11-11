//GZ-S00240 ¹óÑôË«Áú»ª÷ëÑ§Ğ£ ÎâÅæÁØ 
#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005],n,d;
int main(){
	ios::sync_with_std.tie(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if((a[n]-a[i])/(n-1)==(a[2]-a[1])){
			int cz=a[2]-a[1];
			if(d>=2*a&&d<3*a){
				int ans=n-2;
				cout<<n-2<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
