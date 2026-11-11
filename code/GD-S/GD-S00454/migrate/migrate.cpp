#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
int c,t,n,m;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int i1=1,i2=2,i3=3,i4=4;
		while(i4<=n){
			if(a[i4]-a[i1]<=m){
				i4++;
			}
			if(a[i3]-a[i1]>m){
				i1++;
			}
			if(a[i4]-a[i2]>m){
				i2++;
			}
			if(a[i3-1]-a[i1]<=m&&i3-1!=i2){
				i3++;
			}
			if(a[i4-1]-a[i2]<=m&&i4-1!=i3){
				i4++;
			}
			if(a[i4]-a[i1]>m&&a[i4]-a[i2]<=m&&a[i3]-a[i1]<=m&&a[i1]<a[i2]&&a[i2]<a[i3]&&a[i3]<a[i4]&&i4<=n){
				ans++;i4++;
			}
			while(i1>=i2){
				i2++;
			}while(i2>=i3){
				i3++;
			}while(i3>=i4){
				i4++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
